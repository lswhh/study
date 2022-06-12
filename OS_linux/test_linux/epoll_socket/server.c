#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <signal.h> 

#define BUF_SIZE 32768
#define EPOLL_SIZE 50

#define handle_error(msg) \
        do { perror(msg); exit(EXIT_FAILURE); } while (0)

#define MIN(x,y) ( (x)<(y)?(x):(y) )
#define ENDIAN_CONVERT4(dst, src)                    \
    do                                               \
    {                                                \
        *((char *)(dst) + 3) = *((char *)(src) + 0); \
        *((char *)(dst) + 2) = *((char *)(src) + 1); \
        *((char *)(dst) + 1) = *((char *)(src) + 2); \
        *((char *)(dst) + 0) = *((char *)(src) + 3); \
    } while (0)
int main(int argc, char *argv[])
{
	int serv_sock, client_sock;
	struct sockaddr_in serv_addr, client_addr;
	socklen_t addr_sz;
	int str_len, i;
	char buf[BUF_SIZE];
    sigset_t s;
	int len;

	struct epoll_event *ep_events;
	struct epoll_event event;
	int epfd, event_cnt;

	if ( argc != 2 ) 
    {
		printf("Usage : %s <port>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

    sigemptyset(&s);
    sigaddset(&s, SIGPIPE);
    sigprocmask(SIG_BLOCK, &s, NULL);

	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));
	
	if( bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) != 0 )
    {
		handle_error("bind() error");
    }
	if( listen(serv_sock, 5) != 0 )
    {
		handle_error("listen() error");
    }

	epfd = epoll_create( EPOLL_SIZE );
	ep_events = malloc( sizeof(struct epoll_event) * EPOLL_SIZE );

	event.events = EPOLLIN;
	event.data.fd = serv_sock;	
	if ( epoll_ctl(epfd, EPOLL_CTL_ADD, serv_sock, &event) != 0 )
    {
        handle_error("epoll_ctl() error");
    }

	while(1)
	{
		event_cnt = epoll_wait(epfd, ep_events, EPOLL_SIZE, 10);
		if ( event_cnt < 0 )
		{
			puts("epoll_wait() error");
			break;
		}

		for ( i = 0; i < event_cnt; i++ )
		{
			if ( ep_events[i].data.fd == serv_sock )
			{
				addr_sz = sizeof(client_addr);
				client_sock = accept(serv_sock, (struct sockaddr*)&client_addr, &addr_sz);
				event.events = EPOLLIN;
				event.data.fd = client_sock;
				if ( epoll_ctl(epfd, EPOLL_CTL_ADD, client_sock, &event) != 0 )
                {
                    // shutdown(client_sock, SHUT_RDWR);
                    close(client_sock);
                }
                else
                {
                    printf("connected client: %d \n", client_sock);
                }
			}
			else
			{
                    // ssize_t result;
                    //  again:
                    //                     result = ::read (handle, buf, len);
                    // # endif /* PDL_LACKS_POSIX_PROTOTYPES */
                    //     if (result == -1 && errno == EAGAIN)
                    //         errno = EWOULDBLOCK;
                    // #endif /* PDL_WIN32 */
                    //     if (result == -1 && errno == EINTR)
                    //     {
                    //         goto again; // we have to re-read on signal
                    //     }
                    //     return result;
                    read(ep_events[i].data.fd, &str_len, sizeof(str_len));
					ENDIAN_CONVERT4(&len, &str_len);
                    // str_len = ntohl(str_len);

					str_len = read(ep_events[i].data.fd, buf, MIN(len, BUF_SIZE));
					if( str_len == 0 )    // close request!
					{
						epoll_ctl(epfd, EPOLL_CTL_DEL, ep_events[i].data.fd, NULL);
						close(ep_events[i].data.fd);
						printf("closed client: %d \n", ep_events[i].data.fd);
					}
					else
					{
						write(ep_events[i].data.fd, buf, str_len + 1);    // echo!
					}
	
			}
		}
	}
	close(serv_sock);
	close(epfd);
	return 0;
}
// https://gist.github.com/Alexey-N-Chernyshov/4634731