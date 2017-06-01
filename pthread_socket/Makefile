.PHONY:all
all:client tcpsocket_pthread 

client:client.c
	gcc -o $@ $^

tcpsocket_pthread:tcpsocket_pthread.c
	gcc -o $@ $^ -pthread

.PHONY:clean
clean:
	rm -f client tcpsocket_pthread
