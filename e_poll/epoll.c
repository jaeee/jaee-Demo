/*************************************************************************
	> File Name: epoll.c
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Sun 11 Jun 2017 02:42:50 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<sys/epoll.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>

static void Usage(char* proc)
{
	printf("Usage: %s [local_ip] [local_port]\n",proc);
}

int startup(const char* _ip, int _port)
{
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0)
	{
		perror("socket");
		return 2;
	}

	int opt = 1;
	setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(_port);
	local.sin_addr.s_addr = inet_addr(_ip);

	if(bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0)
	{
		perror("bind");
		return 3;
	}

	if(listen(sock, 10) < 0)
	{
		perror("listen");
		return 4;
	}
	return sock;
}

typedef struct fd_buf
{
	int fd;
	char buf[10240];
}fd_buf_t,*fd_buf_p;

static void* alloc_fd_buf(int fd)
{
	fd_buf_p tmp = (fd_buf_p)malloc(sizeof(fd_buf_t));
	if(!tmp)
	{
		perror("malloc");
		return NULL;
	}
	tmp->fd = fd;
	return tmp;
}

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		Usage(argv[0]);
		return 1;
	}

	int listen_sock = startup(argv[1], atoi(argv[2]));

	int epollfd = epoll_create(256);
	if(epollfd < 0)
	{
		perror("epoll_create");
		close(listen_sock);
		return 5;
	}

	struct epoll_event ev;
	ev.events = EPOLLIN;
	ev.data.ptr = alloc_fd_buf(listen_sock);
    
	epoll_ctl(epollfd, EPOLL_CTL_ADD, listen_sock, &ev);

	int nums = 0;
	struct epoll_event evs[256];
	int timeout = -1;

	while(1)
	{
		switch(nums = epoll_wait(epollfd, evs, 256, timeout))
		{
			case -1:
				perror("epoll_wait");
				break;
			case 0:
				printf("timeout...\n");
				break;
			default:
				{
					printf("nums : %d \n",nums);
					int i = 0;
					for(; i < nums; i++)
					{
						fd_buf_p fp = (fd_buf_p)evs[i].data.ptr;
						if(fp->fd == listen_sock && (evs[i].events & EPOLLIN))
						{
							struct sockaddr_in client;
							socklen_t len = sizeof(client);
							int new_sock = accept(listen_sock, (struct sockaddr*)&client, &len);
							if(new_sock < 0)
							{
								perror("accept");
								continue;
							}
							printf("get a new client: ip:%s ,port:%d \n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));

							ev.events = EPOLLIN;
							ev.data.ptr = alloc_fd_buf(new_sock);
							epoll_ctl(epollfd, EPOLL_CTL_ADD, new_sock, &ev);
						}//if
						else if(fp->fd != listen_sock)
						{
			 				if(evs[i].events & EPOLLIN)
							{
		 						ssize_t s = read(fp->fd, fp->buf, sizeof(fp->buf));
								if(s > 0)
								{
	 								fp->buf[s] = 0;
									printf("client say# %s\n", fp->buf);
									ev.events = EPOLLOUT;
									ev.data.ptr = fp;
									epoll_ctl(epollfd, EPOLL_CTL_MOD, fp->fd, &ev);
								}
								else if(s <= 0)
								{
	 								printf("client quit!\n");
									close(fp->fd);
									epoll_ctl(epollfd, EPOLL_CTL_DEL, fp->fd, NULL);
									free(fp);
								}
								else
								{}
							}
							else if(evs[i].events & EPOLLOUT)
							{
					 			const char* msg = "HTTP/1.0 200 OK\r\n\r\n<html><h1>hello epoll!</h1><html>";
								write(fp->fd, msg, strlen(msg));
								close(fp->fd);
								//这里主要用于浏览器测试，所以在输出后关闭文件描述符
								//若使用客户端、Telnet远程登录测试 可以去掉 实现连续发送信息  
								epoll_ctl(epollfd, EPOLL_CTL_DEL, fp->fd, NULL);
								free(fp);
							}
							else
							{}
						}
						else
						{}
					}//for
				}
				break;
		}
	}

	return 0;
}
