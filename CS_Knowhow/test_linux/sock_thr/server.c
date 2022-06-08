#define _POSIX_C_SOURCE 200112L
#define _XOPEN_SOURCE 600
#define _SYSV
#define _VOS_EXTENDED_NAMES

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 
#include <signal.h> 
#include <pthread.h>

char buf[1025];

void signal_handler(int signo)
{
    printf("signal handler = %d\n", signo);
}

void *thr_read(void *param)
{
    int connfd = (int)param;
    int ret;

    ret = read(connfd, buf, sizeof(buf)-1);
    printf("read() : ret = %d, errno = %d\n", ret, errno);

    if (ret > 0)
    {
        buf[ret] = 0;

        fputs(buf, stdout);
    }

    return 0;
}

void *thr_write(void *param)
{
    int connfd = (int)param;
    int ret;

    ret = write(connfd, buf, strlen(buf) + 1); 
    printf("write() : ret = %d, errno = %d\n", ret, errno);

    return 0;
}

void *thr_run(void *param)
{
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr; 
    int ret;
    pthread_t tid;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(buf, '0', sizeof(buf)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5000); 

    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 

    listen(listenfd, 10); 

    while(1)
    {
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); 
        if (connfd == -1)
        {
            printf("connnfd = -1\n");
            continue;
        }

        printf("accepted\n");

        pthread_create(&tid, NULL, thr_read, (void*)connfd);
        pthread_join(tid, NULL);

        //ret = read(connfd, buf, sizeof(buf)-1);
        //printf("read() : ret = %d, errno = %d\n", errno);

        pthread_create(&tid, NULL, thr_write, (void*)connfd);
        pthread_join(tid, NULL);

        //ret = write(connfd, buf, strlen(buf) + 1); 
        //printf("write() : ret = %d, errno = %d\n", ret, errno);

        close(connfd);

        printf("closed\n");
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t tid;
    sigset_t s;

    sigemptyset(&s);
    sigaddset(&s, SIGPIPE);
    sigprocmask(SIG_BLOCK, &s, NULL);

    //signal(17, SIG_DFL);
    //signal(SIGPIPE, signal_handler);
    signal(SIGPIPE, signal_handler);
    pthread_create(&tid, NULL, thr_run, NULL);
    pthread_join(tid, NULL);
    
    return 0;
}
