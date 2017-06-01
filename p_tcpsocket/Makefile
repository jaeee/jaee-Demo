.PHONY:all
all:tcpsocket_proc client

tcpsocket_proc:tcpsocket_proc.c
	gcc -o $@ $^
client:client.c
	gcc -o $@ $^


.PHONY:clean
clean:
	rm -f tcpsocket_proc client
