/*************************************************************************
	> File Name: tcpsocket_proc.c
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Wed 31 May 2017 11:32:25 PM CST
 ************************************************************************/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>

static void usage(const char* proc)
{
	printf("%s [ip] [port]", proc);
}

int startup(const char* _ip, int _port)
{
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0)
	{
		perror("socket");
		return 2;
	}

	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(_port);
	local.sin_addr.s_addr = inet_addr(_ip);
    
	//允许创建多个端口号相同但IP不同的套接字
	int opt = 1;
	setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	if(bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0)
	{
		perror("bind");
		return 3;
	}

	if(listen(sock, 5) < 0)
	{
		perror("listen");
		return 4;
	}
	return sock;
}

void* handler(void* arg)
{
    char buf[10240];
	int newsock = (int)arg;
	//printf("connect...  ip is: %s  port is: %d \n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
	while(1)
	{
		ssize_t s = read(newsock, buf, sizeof(buf)-1);
		if(s > 0)
		{
 	 		buf[s] = '\0';
			printf("client say# %s\n",buf);
	 		write(newsock, buf, strlen(buf));
		}
		else if(s == 0)
			{
				printf("client quit ...\n");
			 	break; 
			}
			else
	 			break;
	}
}

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		usage(argv[0]);
		return 1;
	}
	int listen_sock = startup(argv[1], atoi(argv[2]));

	//char buf[10240];
	struct sockaddr_in client;
	socklen_t len = sizeof(client);

	while(1)
	{
		int new_sock = accept(listen_sock, (struct sockaddr*)&client, &len);

		if(new_sock < 0)
		{
			perror("accept");
			return 2;
		}

		//多线程模式
		
		pthread_t tid;
		if(pthread_create(&tid, NULL, handler, (void*)new_sock)<0)
		{
			perror("pthread");
			return 3;
		}
		pthread_detach(&tid);
	}		
	return 0;
}
