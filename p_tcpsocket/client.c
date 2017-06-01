/*************************************************************************
	> File Name: client.c
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Wed 24 May 2017 12:00:38 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>

int start(int _port, const char* _ip)
{
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0)
	{
		perror("socket");
		exit(0);
	}
	return sock;
}

int main(int argc, char * argv[])
{
	//不需要监听、绑定、accept
	if(argc != 3)
	{
		return 1;
	}
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0)
	{
		perror("sock");
		exit(1);
	}

	struct sockaddr_in peer;
	peer.sin_family = AF_INET;
	peer.sin_port = htons(atoi(argv[2]));
	peer.sin_addr.s_addr = inet_addr(argv[1]);

	if(connect(sock, (struct sockaddr*)&peer, sizeof(peer)) < 0)
	{
		perror("connect...");
		exit(2);
	}
	
	char buf[1024];

	while(1)
	{
		printf("please user enter: ");
		fflush(stdout);
		ssize_t s = read(0, buf, sizeof(buf)-1);

		if(s > 0)
		{
			buf[s-1] = 0;
			write(sock, buf, strlen(buf));
			ssize_t s1 = read(sock, buf,sizeof(buf)-1);

			if(s1 > 0)
			{
				buf[s1] = 0;
				printf("server say $ :%s\n",buf);
				//read(sock, buf, sizeof(buf)-1);
			}
		}
	}
	close(sock);
}
