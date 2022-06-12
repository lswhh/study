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
    double d = 4.5;
    double d2 = -0.000314159265358979;
    char t[100];

    printf("%.15G\n", d);
    printf("%.7G\n", d2);

    return 0;
}
