#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define handle_error(msg) \
        do { perror(msg); exit(EXIT_FAILURE); } while (0)

int main(int argc, char *argv[])
{
	int sock;
	char message[BUF_SIZE];
	int str_len;
	struct sockaddr_in serv_addr;

	if ( argc!=3 ) {
		printf("Usage : %s <IP> <port>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	sock = socket( PF_INET, SOCK_STREAM, 0 );   
	if ( sock == -1 )
		handle_error("socket() error");
	
	memset( &serv_addr, 0, sizeof(serv_addr) );
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));
	
	if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
		handle_error("connect() error!");
	else
		puts("Connected.");
	
	while(1) 
	{
		// fputs("Input message(Q to quit): ", stdout);
		// fgets(message, BUF_SIZE, stdin);
		// usleep(100000);
		sleep(1);
		memcpy(message,"testtesttesttest\n", 17);
		if ( strcmp(message,"q\n") == 0 || strcmp(message,"Q\n") == 0 )
			break;
        str_len = strlen(message);
		str_len = htonl(str_len);
		write(sock, &str_len, sizeof(str_len));
		write(sock, message, strlen(message));
		str_len = strlen(message);
		str_len = read(sock, message, BUF_SIZE - 1);
		message[str_len] = 0;
		printf("Message from server: %s\n", message);
	}
	
	close(sock);
	return 0;
}
