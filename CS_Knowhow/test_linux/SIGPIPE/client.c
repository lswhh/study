#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int sockfd = 0, n = 0;
    char recvBuff[1024];
    struct sockaddr_in serv_addr; 
    fd_set sfdset;
    struct timeval tv;
    int ret = 0;

    if(argc != 2)
    {
        printf("\n Usage: %s <ip of server> \n",argv[0]);
        return 1;
    } 

    memset(recvBuff, '0',sizeof(recvBuff));
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Error : Could not create socket \n");
        return 1;
    } 

    memset(&serv_addr, '0', sizeof(serv_addr)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5000); 

    if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0)
    {
        printf("\n inet_pton error occured\n");
        return 1;
    } 


    if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\n Error : Connect Failed \n");
        return 1;
    } 

    printf("sockfd: %d\n", sockfd);
    //sleep(10);
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    FD_ZERO(&sfdset);
    FD_SET(sockfd, &sfdset);
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
        printf("errno: %d, errno:%d\n", errno, errno);
FD_CLR(sockfd, &sfdset);
FD_SET(sockfd, &sfdset);
    }
    while ( (n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0)
    {
        recvBuff[n] = 0;
        if(fputs(recvBuff, stdout) == EOF)
        {
            printf("\n Error : Fputs error\n");
        }
    } 

    if(n < 0)
    {
        printf("\n Read error \n");
    } 

    return 0;
}
