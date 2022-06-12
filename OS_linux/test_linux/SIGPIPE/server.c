#define _POSIX_C_SOURCE 200112L
#define _XOPEN_SOURCE 600
#define _SYSV
#define _VOS_EXTENDED_NAMES
#define _FILE_OFFSET_BITS 64

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

void signal_handler(int signo)
{
    printf("signal handler = %d\n", signo);
}

void new_write( int connfd )
{
    int ret;
    char sendBuff[32760];

    printf("write -> ");
    ret = write(connfd, sendBuff, sizeof(sendBuff)); 
    printf("write() : ret = %d, errno = %d\n", ret, errno);
}

void *thr_run(void *param)
{
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr; 
    int ret;
    //sigset_t s;
    //sigemptyset(&s);
    //sigaddset(&s, SIGPIPE);
    //sigprocmask(SIG_BLOCK, &s, NULL);

    char sendBuff[32760];

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5000); 

    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 

    listen(listenfd, 10); 

    while(1)
    {
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); 

        printf("sleep 5\n");
        sleep(5);

        new_write( connfd );
        new_write( connfd );
        new_write( connfd );
        new_write( connfd );
        new_write( connfd );

        close(connfd);

        printf("closed\n");
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t tid;
    sigset_t s;

    if(fork() !=0)
    {
      _exit(0);
    }
    //sigemptyset(&s);
    //sigaddset(&s, SIGPIPE);
    //if (sigprocmask(SIG_BLOCK, &s, NULL) != 0 )
    //{
    //    printf("sigprocmask fail\n");
    //    exit( -1 );
    //}
    //signal(17, SIG_DFL);
    signal(SIGPIPE, signal_handler);

    pthread_create(&tid, NULL, thr_run, NULL);
    pthread_join(tid, NULL);
    
    return 0;
}
