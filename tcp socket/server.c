/*************************************************************************
	> File Name: server.c
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Wed 24 May 2017 12:00:07 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#define _BACKLOG_ 10

int start(const char* _ip, int _port)
{

	int sock = socket(AF_INET, SOCK_STREAM, 0);//1.创建套接字 返回值相当文件描述符
	if(sock < 0)
	{
		perror("socket");
		exit(2);
	}

	//绑定
	struct sockaddr_in server_socket;
	server_socket.sin_family = AF_INET;
	server_socket.sin_port = htons(_port);
	server_socket.sin_addr.s_addr = inet_addr(_ip);

	if(bind(sock, (struct sockaddr*)&server_socket, sizeof(server_socket)) < 0)
	{
		perror("bind error!");
		exit(3);
	}

	if(listen(sock, _BACKLOG_) < 0)
	{
		perror("listen");
		exit(4);
	}
	return sock;
}

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		printf("argv");
		return 1;
	}
	int listen_sock = start(argv[1],atoi(argv[2]));
	struct sockaddr_in remote;
	int len = sizeof(remote);
	char buf[1024];
	while(1)
	{
		int sock = accept(listen_sock, (struct sockaddr*)&remote,&len);
		if(sock < 0)
		{
			perror("accept error");
			continue;
		}

		printf("connect...  ip is: %s  port is: %d \n", inet_ntoa(remote.sin_addr), ntohs(remote.sin_port));
		while(1)
		{
			ssize_t s = read(sock, buf, sizeof(buf)-1);
			if(s > 0)
			{
		 		buf[s] = '\0';
				printf("client :# %s\n", buf);
				write(sock, buf,strlen(buf));
			}
			else
			{
		 		printf("client close....\n");
				break;
			}
		}
	}
	close(listen_sock);
	return 0;
}

