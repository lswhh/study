#define _POSIX_C_SOURCE 200112L
#define _XOPEN_SOURCE 600
//#define _SYSV
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
#include <sys/select.h>


void waitSelect(int sockfd)
{
    char recvBuff[1024];
    struct sockaddr_in serv_addr;
    fd_set sfdset;
    struct timeval tv;
    int ret = 0;


    tv.tv_sec = 1;
    tv.tv_usec = 0;
    FD_ZERO(&sfdset);
    FD_SET(sockfd, &sfdset);

    while( (ret = select(sockfd + 1, &sfdset, 0, 0, &tv)) <= 0)
    {
if(FD_ISSET(sockfd, &sfdset) != 0)
{
printf("fd set not ok 2\n");
FD_CLR(sockfd, &sfdset);
FD_SET(sockfd, &sfdset);
}
if(FD_ISSET(sockfd, &sfdset) != 0)
{
printf("fd set ok 3\n");
}
        printf("timeout: %d, %d, ret:%d\n", tv.tv_sec, tv.tv_usec, ret);
        printf("errno: %d, os_errno:%d\n", errno, os_errno);
FD_CLR(sockfd, &sfdset);
FD_SET(sockfd, &sfdset);
    }
if(FD_ISSET(sockfd, &sfdset) != 0)
{
printf("fd set ok X\n");
}
}

void *thr_run(void *param)
{
    int sockfd = 0, n = 0;
    char recvBuff[32768];
    struct sockaddr_in serv_addr;


    memset(recvBuff, '0',sizeof(recvBuff));
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Error : Could not create socket \n");
        return NULL;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5000);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\n inet_pton error occured\n");
        return NULL;
    }


    if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\n Error : Connect Failed \n");
        return NULL;
    }

    printf("sockfd: %d\n", sockfd);
    //sleep(10);
/*
if(FD_ISSET(sockfd, &sfdset) != 0)
{
printf("fd set ok 1\n");
    if( (n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0)
    {
        recvBuff[n] = 0;
        if(fputs(recvBuff, stdout) == EOF)
        {
            printf("\n Error : Fputs error\n");
        }
    }
}
*/
waitSelect(sockfd);
    //while ( (n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0)
    while ( (n = read(sockfd, recvBuff, 32768)) > 0)
    {
        recvBuff[n] = 0;
        if(fputs(recvBuff, stdout) == EOF)
        {
            printf("\n Error : Fputs error\n");
        }
waitSelect(sockfd);
    }

    if(n < 0)
    {
        printf("\n Read error \n");
    }


    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t tid;
    sigset_t s;
/*
    if(fork() !=0)
    {
      _exit(0);
    }
    sigemptyset(&s);
    sigaddset(&s, SIGPIPE);
    sigprocmask(SIG_BLOCK, &s, NULL);
*/
    //signal(17, SIG_DFL);
    //signal(SIGPIPE, signal_handler);

    pthread_create(&tid, NULL, thr_run, NULL);
    pthread_join(tid, NULL);
    
    return 0;
}
