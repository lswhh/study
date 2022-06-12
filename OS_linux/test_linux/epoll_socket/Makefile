.PHONY: all clean


LDFLAGS= -pthread  -lpthread
all:
	gcc -g -O3 -o server server.c $(LDFLAGS)
	gcc -g -O3 -o client client.c $(LDFLAGS)

clean:
	rm -rf server client