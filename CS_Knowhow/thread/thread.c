#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

typedef void * (*threadFunc)(void*);

void * sample(void * aArg)
{
    printf("sample thread\n");
    sleep(1);
    printf("end Thread\n");
}

int main()
{
    pthread_t tid;
    threadFunc tFunc = &sample;
    pthread_create(&tid, NULL, tFunc, NULL);
    pthread_join(tid, NULL);

    return 0;
}