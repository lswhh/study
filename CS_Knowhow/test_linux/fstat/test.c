#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
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
    int ret;
    struct stat s;

    ret = stat("t_lob_4_in_000000001_000002.lob", &s);

    printf("ret = %d, mode = %d, size = %d, rdev = %d\n", ret, s.st_mode, s.st_size, s.st_rdev);

    return 0;
}
