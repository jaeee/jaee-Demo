/*************************************************************************
	> File Name: udp_client.c
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Fri 26 May 2017 08:32:03 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>

static void usage(const char* proc)
{
	printf("%s [ip] [port]\n",proc);
}

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		usage(argv[0]);
		return 1;
	}

	int sock = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock < 0)
	{
		perror("socket");
		return 2;
	}

	struct sockaddr_in peer;
	peer.sin_family = AF_INET;
	peer.sin_port = htons(atoi(argv[2]));
	peer.sin_addr.s_addr = inet_addr(argv[1]);

	char buf[1024];
	while(1)
	{
		printf("Please Enter ...");
		fflush(stdout);

		ssize_t s = read(0, buf, sizeof(buf)-1);
		if(s > 0)
		{
			buf[s] = 0;
			sendto(sock, buf, sizeof(buf), 0, (struct sockaddr*)&peer, sizeof(peer));
			ssize_t _s = recvfrom(sock, buf, sizeof(buf)-1, 0, NULL, NULL);
			printf("server echo# : %s\n", buf);
		}
		else if(s == 0)
		{
			printf("client quit...");
		}
	}
	close(sock);
	return 0;
}
