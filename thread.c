#include <pthread.h>
#include <stdio.h>

void * sample()
{
    printf("sample thread\n");
    sleep(1);
    printf("end Thread\n");
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, &sample, NULL);
    pthread_join(tid, NULL);

    return 0;
}