.PHONY:all
all:epoll client

epoll:epoll.c
	gcc -o $@ $^

client:client.c
	gcc -o $@ $^
.PHONY:clean
clean:
	rm -f epoll client
