#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>


pthread_mutex_t mutex;
int cnt=0;

void *count(void *arg){
    int i;
    char* name = (char*)arg;

    for (i = 0; i <10; i++)
    {
        pthread_mutex_lock(&mutex);
        cnt++;
        pthread_mutex_unlock(&mutex);
        printf("%s cnt: %d\n", name,cnt);
        usleep(1);
    }
}

int main()
{
    pthread_t thread1,thread2;

    pthread_mutex_init(&mutex,NULL);

    pthread_create(&thread1, NULL, count, (void *)"thread1");
    pthread_create(&thread2, NULL, count, (void *)"thread2");

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex);
    return 0;
}