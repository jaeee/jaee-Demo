/*************************************************************************
	> File Name: my_poll.c
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Mon 12 Jun 2017 03:12:01 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/stat.h>
#include<poll.h>

#define _SIZE 1024
struct pollfd arr_pollfd[_SIZE];

static void Usage(char* proc)
{
	printf("Usage : %s [local_ip] [local_port]\n", proc);
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

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		Usage(argv[0]);
		return 1;
	}

	int listen_sock = startup(argv[1], atoi(argv[2]));

    arr_pollfd[0].fd = listen_sock;//将负责监听连接的fd注册事件
	arr_pollfd[0].events = POLLIN;
	int i = 1;
	//初始化数组中的描述符
	for(;i < _SIZE ;i++)
	{
		arr_pollfd[i].fd = -1;
	}
	int timeout = -1;//设置超时时间
	int nums = 0;
	while(1)
	{
		switch(nums = poll(arr_pollfd, _SIZE, timeout))
		{
			case -1:
				perror("poll");
				break;
			case 0:
				printf("timeout...\n");
				break;
			default:
				{
					int k = 0;
					for(; k < _SIZE;k++)
					{
						char buf[10240];
						if(arr_pollfd[k].fd == listen_sock && arr_pollfd[k].revents & POLLIN)
						{
							struct sockaddr_in client;
							socklen_t len = sizeof(client);
                            //接受返回连接 listen_sock == arr_pollfd[0].fd
							int new_sock = accept(arr_pollfd[k].fd, (struct sockaddr*)&client, &len);
							if(new_sock < 0)
							{
								perror("accept");
								continue;
							}

							printf("get a new connect : ip %s , port %d \n",\
									inet_ntoa(client.sin_addr),ntohs(client.sin_port));
                            //将新的描述符（new_sock）添加进数组中
							int j = 1;
							for(; j < _SIZE;j++)
							{
								if(arr_pollfd[j].fd < 0)
								{
									arr_pollfd[j].fd = new_sock;
									arr_pollfd[j].events = POLLIN;
									break;
								}
							}
							if(j == _SIZE)
							{
								printf("超出连接数！！！\n");
								close(new_sock);
								return 5;
							}
						}//if
						else if(arr_pollfd[k].fd > 0)
						{
							//连接事件就绪
							if(arr_pollfd[k].revents & POLLIN)
							{
								//char buf[1024];
								ssize_t s = read(arr_pollfd[k].fd, buf, sizeof(buf)-1);
								if(s > 0)
								{
									buf[s] = 0;
                                    printf("client say # %s\n",buf);
									arr_pollfd[k].events = POLLOUT;
								}
								else
								{
									printf("client quit!\n");
									close(arr_pollfd[k].fd);
									arr_pollfd[k].fd = -1;
								}
							}
							else if(arr_pollfd[k].revents & POLLOUT)
							{
								//写事件就绪
								const char* msg = "HTTP/1.1 200 OK\r\n\r\n<html><h1>Hello Poll!</h1></html>";
								write(arr_pollfd[k].fd, msg, strlen(msg));
								close(arr_pollfd[k].fd);
								arr_pollfd[k].fd = -1;
							}
						}//else if
					}//for
				}//default
				break;
		}//switch
	}//while
	return 0;
}
