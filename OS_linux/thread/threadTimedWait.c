#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

pthread_cond_t g_condition;
pthread_mutex_t g_mutex; 

void *thred_func()
{
    struct timeval now;
    struct timespec ts;
    struct timeval endTime;
    double diffTime;

    printf("start thred_func..\n");
    gettimeofday(&now, NULL);
    ts.tv_sec = now.tv_sec + 5;
    ts.tv_nsec = now.tv_usec * 1000;

    pthread_mutex_lock(&g_mutex);
    printf("now waiting wakeup signal about 5 sec.., and lock release\n");
    pthread_cond_timedwait(&g_condition, &g_mutex, &ts);
    printf("ok, i'm wakeup.. with lock\n");
    pthread_mutex_unlock(&g_mutex);

    gettimeofday(&endTime, NULL);
    diffTime = ( endTime.tv_sec - now.tv_sec ) + (( endTime.tv_usec - now.tv_usec ) / 1000000);
    printf("%f sec\n", diffTime);

    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t thread;
    struct timespec ts;

    pthread_mutex_init(&g_mutex, NULL);
    pthread_cond_init(&g_condition, NULL);

    pthread_create(&thread, NULL, thred_func, NULL);

    sleep(1);
    ts.tv_sec = 0;
    ts.tv_nsec = 10000000;
    nanosleep(&ts, NULL);
    pthread_mutex_lock(&g_mutex);
    printf("now send wakeup signal.. \n");
    pthread_cond_signal(&g_condition);
    pthread_mutex_unlock(&g_mutex);

    pthread_join(thread, NULL);
    printf("thread's working is done.\n");

    pthread_cond_destroy(&g_condition);
    pthread_mutex_destroy(&g_mutex);
    return 0;
}