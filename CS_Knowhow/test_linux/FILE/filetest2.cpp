#define _POSIX_C_SOURCE 200112L
#define _FILE_OFFSET_BITS 64
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

pthread_t threads[5];
pthread_attr_t attr[5];
int done[5];

void *thread_main(void *);

int main(void)
{
        int i;
        int rc;
        int status;
        long long result=0;
        int fd =0;
        long long sDummyBuf=0 ;
       off_t res;
        printf("pri rr file %d\n",PRI_RR_MAX);
printf("sizeof off_t:%d\n", sizeof(off_t));

        fd = open("aaa2.txt",O_RDWR|O_CREAT , S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP  | S_IROTH | S_IWOTH  );

        printf("create file %d\n",fd);

        for (i = 0; i < 5; i++)
        {
                done[i] = 0;
                pthread_attr_init(&attr[i]);
                pthread_attr_setschedpolicy( &attr[i], SCHED_RR );
                pthread_create(&threads[i], &attr[i], &thread_main, (void *)i);
                printf("create %d\n", i);
        }

        printf("middle\n");

        rc = pthread_join(threads[4], (void **)&status);
        write(fd,(void*)&sDummyBuf,sizeof(sDummyBuf));

        res =  lseek(fd,(long)1024*1024*5,SEEK_SET);
printf("write: %p", &write);
printf("lseek: %p", &lseek);


        printf("res %d \n",res);
        write(fd,(void*)&sDummyBuf,sizeof(sDummyBuf));
        printf("write clear\n");


        for (i = 3; i >= 0; i--)
        {
                done[i] = 1;
                printf("done  %d\n",i);
                 rc = pthread_join(threads[i], (void **)&status);
                if (rc == 0)
                {
                        printf("Completed join with thread %d status= %d\n",i, status);
                }
                else
                {
                        printf("ERROR; return code from pthread_join() is %d, thread %d\n", rc, i);
                                 return -1;
                }
        }
        close(fd);
        return 0;
}

void *thread_main(void *arg)
{
        long long i;
        long long result=0;

        if( (int)arg != 4 )
       {
        while (!done[(int)arg])
        {
           printf("str thread: %d, result = %lld\n", (int)arg, result);
           for (i=0 ; i < 10000000 ; i++)
           {
              result++;
           }
           printf("end thread: %d, result = %lld\n", (int)arg, result);
        }
       }
       else
       {
           printf("str thread: %d, result = %lld\n", (int)arg, result);
    printf("end thread: %d, result = %lld\n", (int)arg, result);
       }
        pthread_exit((void *) 0);
}

