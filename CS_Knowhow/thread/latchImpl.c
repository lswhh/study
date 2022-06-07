#define __USE_GNU 
#include <assert.h>
#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

#define RESULT_SUCCESS (0)
#define EXCEPTION_END EXCEPTION_END_LABEL:
#define TEST_RAISE( a, b ) { if( a ) {  goto b; } }
#define TEST_END( a ) { if( a ) {  goto EXCEPTION_END_LABEL; } }
#define EXCEPTION(a) goto EXCEPTION_END_LABEL; a:
#define HANDLE_ERROR(en, msg) \
        do { errno = en; perror(msg); } while (0)
#define THREAD_ID_NULL (0)

typedef enum {
    lock_false = 0,
    lock_true = 1,
} lockBool;

typedef struct latchObj {
    int mode;
    pthread_t writeTID;
    pthread_mutex_t mutex;
} latchObj;

typedef struct latchOP {
    int (*initialize)( latchObj* );
    int (*destroy)( latchObj* );
    int (*lock)( latchObj* );
    int (*unlock)( latchObj* );
} latchOP;

int latchInitialize(latchObj * aLatchObj )
{
    int result = 0;
    pthread_mutexattr_t mutexAttr;

    result = pthread_mutexattr_init(&mutexAttr);
    TEST_RAISE(result != RESULT_SUCCESS, mutexattr_init_error);

    result = pthread_mutexattr_setpshared(&mutexAttr, PTHREAD_PROCESS_SHARED);
    TEST_RAISE(result != RESULT_SUCCESS, mutexattr_setpshared_error);

    result = pthread_mutex_init(&(aLatchObj->mutex), &mutexAttr);
    TEST_RAISE(result != RESULT_SUCCESS, mutex_init_error);

    aLatchObj->writeTID = THREAD_ID_NULL;

    return RESULT_SUCCESS;

    EXCEPTION(mutexattr_init_error)
    {
        HANDLE_ERROR(result, "mutexattr_init_error");
    }
    EXCEPTION(mutexattr_setpshared_error)
    {
        HANDLE_ERROR(result, "mutexattr_setpshared_error");
    }
    EXCEPTION(mutex_init_error)
    {
        HANDLE_ERROR(result, "mutex_init_error");
    }
    EXCEPTION_END;

    return result;
}

int latchDestroy(latchObj * aLatchObj )
{
    int result = 0;
    result = pthread_mutex_destroy(&(aLatchObj->mutex));
    TEST_END( result != RESULT_SUCCESS );

    return RESULT_SUCCESS;
    
    EXCEPTION_END;
    HANDLE_ERROR(result, "pthread_mutex_destroy");
    
    return result;
}

int tryLockRead( latchObj * aLatchObj, lockBool * aOutIsLockSuccess )
{
    int result = 0;
    pthread_t threadID = pthread_self();

    result = pthread_mutex_lock( &aLatchObj->mutex );
    TEST_RAISE( result != RESULT_SUCCESS, mutex_lock_err );

    if(aLatchObj->mode >= 0)
    {
        aLatchObj->mode++;
        *aOutIsLockSuccess = lock_true;
    }
    else
    {
        if(aLatchObj->writeTID == threadID)
        {
            /*
             * This thread holds X latch
             * negative mode value represents X latch
             */
            aLatchObj->mode--;
            *aOutIsLockSuccess = lock_true;
        }
        else
        {
            *aOutIsLockSuccess = lock_false;
        }
    }

    result = pthread_mutex_unlock(&aLatchObj->mutex);
    TEST_RAISE( result != RESULT_SUCCESS, mutex_unlock_err );

    return RESULT_SUCCESS;

    EXCEPTION(mutex_lock_err)
    {
        HANDLE_ERROR(result, "pthread_mutex_lock");
    }
    EXCEPTION(mutex_unlock_err)
    {
        HANDLE_ERROR(result, "pthread_mutex_unlock");
    }

    EXCEPTION_END;
    
    return result;
}

int lockRead( latchObj * aLatchObj )
{
    int result;
    lockBool  sSuccess;

    result = tryLockRead(aLatchObj, &sSuccess);
    TEST_RAISE( result != RESULT_SUCCESS, tryLockRead_err );    
    
    if(sSuccess == lock_false)
    {
        do
        {
            pthread_yield();
            result = tryLockRead(aLatchObj, &sSuccess);
            TEST_RAISE( result != RESULT_SUCCESS, tryLockRead_err );    
        } while(sSuccess == lock_false);
    }

    return RESULT_SUCCESS;

    EXCEPTION(tryLockRead_err)
    {
        HANDLE_ERROR(result, "tryLockRead");
    }
    EXCEPTION_END;

    return result;
}
int tryLockWrite( latchObj * aLatchObj, lockBool * aOutIsLockSuccess )
{
    int result = 0;

    pthread_t threadID = pthread_self();

    result = pthread_mutex_lock( &aLatchObj->mutex );
    TEST_RAISE( result != RESULT_SUCCESS, mutex_lock_err );

    if(aLatchObj->mode == 0)
    {
        aLatchObj->mode = -1;
        aLatchObj->writeTID = threadID;
        *aOutIsLockSuccess = lock_true;
    }
    else
    {
        if(aLatchObj->mode > 0)
        {
            *aOutIsLockSuccess = lock_false;
        }
        else
        {
            if(aLatchObj->writeTID == threadID)
            {
                aLatchObj->mode--;
                *aOutIsLockSuccess = lock_true;
            }
            else
            {
                *aOutIsLockSuccess = lock_false;
            }
        }
    }

    result = pthread_mutex_unlock(&aLatchObj->mutex);
    TEST_RAISE( result != RESULT_SUCCESS, mutex_unlock_err );

    return RESULT_SUCCESS;

    EXCEPTION(mutex_lock_err)
    {
        HANDLE_ERROR(result, "pthread_mutex_lock");
    }
    EXCEPTION(mutex_unlock_err)
    {
        HANDLE_ERROR(result, "pthread_mutex_unlock");
    }

    EXCEPTION_END;
    
    return result;
}

int lockWrite( latchObj * aLatchObj )
{
    int result;
    lockBool  sSuccess;

    result = tryLockWrite(aLatchObj, &sSuccess);
    TEST_RAISE( result != RESULT_SUCCESS, tryLockWrite_err );    
    if(sSuccess == lock_false)
    {
        do
        {
            (void)pthread_yield();
            result = tryLockWrite(aLatchObj, &sSuccess);
            TEST_RAISE( result != RESULT_SUCCESS, tryLockWrite_err );    
        } while(sSuccess == lock_false);
    }
    else
    {
        /* lock acquire: do nothing */
    }

    return RESULT_SUCCESS;

    EXCEPTION(tryLockWrite_err)
    {
        HANDLE_ERROR(result, "tryLockWrite");
    }

    EXCEPTION_END;

    return result;
}

int unlock( latchObj * aLatchObj )
{
    int result = 0;

    result = pthread_mutex_lock( &aLatchObj->mutex );
    TEST_RAISE( result != RESULT_SUCCESS, mutex_lock_err );

    if (aLatchObj->mode > 0) /* for read */
    {
        aLatchObj->mode--; /* decrease read latch count */
    }
    else /* for write */
    {
        assert(aLatchObj->writeTID == pthread_self());

        aLatchObj->mode++; /* Decrease write latch count (reverse) */

        if (aLatchObj->mode == 0)
        {
            aLatchObj->writeTID = THREAD_ID_NULL;
        }
        else
        {
            /* still I'm holding this latch, for recursive write lock */
        }
    }

    result = pthread_mutex_unlock(&aLatchObj->mutex);
    TEST_RAISE( result != RESULT_SUCCESS, mutex_unlock_err );

    return RESULT_SUCCESS;

    EXCEPTION(mutex_lock_err)
    {
        HANDLE_ERROR(result, "pthread_mutex_lock");
    }
    EXCEPTION(mutex_unlock_err)
    {
        HANDLE_ERROR(result, "pthread_mutex_unlock");
    }
    EXCEPTION_END;
    
    return result;
}

#define handle_error_en(en, msg) \
        do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

#define handle_error(msg) \
        do { perror(msg); exit(EXIT_FAILURE); } while (0)

struct thread_info {    /* Used as argument to thread_start() */
    pthread_t thread_id;        /* ID returned by pthread_create() */
    int       thread_num;       /* Application-defined thread # */
    char     *argv_string;      /* From command-line argument */
};

static void *
thread_start(void *arg)
{
    struct thread_info *tinfo = arg;
    char *uargv, *p;

    printf("Thread %d: top of stack near %p; argv_string=%s\n",
            tinfo->thread_num, &p, tinfo->argv_string);

    uargv = strdup(tinfo->argv_string);
    if (uargv == NULL)
        handle_error("strdup");

    for (p = uargv; *p != '\0'; p++)
        *p = toupper(*p);

    return uargv;
}

int
main(int argc, char *argv[])
{
    char *p = NULL;
    int s, tnum, opt, num_threads;
    struct thread_info *tinfo;
    pthread_attr_t attr;
    int stack_size;
    void *res;

    printf("main func init address: %p\n", &p);
    printf("text pointer address: %p\n", &"TEXT");
    /* The "-s" option specifies a stack size for our threads */

    stack_size = -1;
    while ((opt = getopt(argc, argv, "s:")) != -1) {
        switch (opt) {
        case 's':
            stack_size = strtoul(optarg, NULL, 0);
            break;

        default:
            printf("result: %c", opt);
            fprintf(stderr, "Usage: %s [-s stack-size] arg...\n",
                    argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    num_threads = argc - optind;

    /* Initialize thread creation attributes */

    s = pthread_attr_init(&attr);
    if (s != 0)
        handle_error_en(s, "pthread_attr_init");

    if (stack_size > 0) {
        s = pthread_attr_setstacksize(&attr, stack_size);
        if (s != 0)
            handle_error_en(s, "pthread_attr_setstacksize");
    }

    /* Allocate memory for pthread_create() arguments */

    tinfo = calloc(num_threads, sizeof(struct thread_info));
    if (tinfo == NULL)
        handle_error("calloc");
    /* Create one thread for each command-line argument */

    for (tnum = 0; tnum < num_threads; tnum++) {
        tinfo[tnum].thread_num = tnum + 1;
        tinfo[tnum].argv_string = argv[optind + tnum];

        /* The pthread_create() call stores the thread ID into
            corresponding element of tinfo[] */

        s = pthread_create(&tinfo[tnum].thread_id, &attr,
                            &thread_start, &tinfo[tnum]);
        if (s != 0)
            handle_error_en(s, "pthread_create");
    }

    /* Destroy the thread attributes object, since it is no
        longer needed */

    s = pthread_attr_destroy(&attr);
    if (s != 0)
        handle_error_en(s, "pthread_attr_destroy");

    /* Now join with each thread, and display its returned value */

    for (tnum = 0; tnum < num_threads; tnum++) {
        s = pthread_join(tinfo[tnum].thread_id, &res);
        if (s != 0)
            handle_error_en(s, "pthread_join");

        printf("Joined with thread %d; returned value was %s\n",
                tinfo[tnum].thread_num, (char *) res);
        free(res);      /* Free memory allocated by thread */
    }

    free(tinfo);
    exit(EXIT_SUCCESS);
}