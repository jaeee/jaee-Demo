/*************************************************************************
	> File Name: client.c
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Sun 04 Jun 2017 11:12:07 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<sys/stat.h>
#include<unistd.h>
static void Usage(char * proc)
{
	printf("Usage : %s [ip] [port]\n");
}

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		Usage(argv[0]);
		return 1;
	}

	int sock = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in peer;
	peer.sin_family = AF_INET;
	peer.sin_port = htons(atoi(argv[2]));
	peer.sin_addr.s_addr = inet_addr(argv[1]);

	if(connect(sock, (struct sockaddr*)&peer, sizeof(peer)) < 0)
	{
		perror("connect");
		return 2;
	}

	char buf[10240];
	//int sfd = dup(STDOUT_FILENO);
	while(1)
	{
		printf("Please Enter : ");
		fflush(stdout);
		ssize_t s = read(0, buf, sizeof(buf)-1);
        int sfd = dup(STDOUT_FILENO);
		if(s > 0)
		{
			buf[s-1] = 0;
			//write(sock, buf, strlen(buf));
			//输出重定向
            //close(1);
		   // int new_fd = dup(sock);
		   int new_fd = dup2(sock, 1);
            if(new_fd == -1)
		    {
		 	   perror("dup()");
		 	   return -1;
		    }
            printf("%s",buf);
		    fflush(stdout);
			//恢复stdout
			dup2(sfd, STDOUT_FILENO);
			
	        ssize_t _s = read(sock, buf, sizeof(buf)-1);
		    if(_s > 0)
		    {
			   buf[_s] = 0;
			   printf("sever # %s \n", buf);
		    }
		}
	}
	close(sock);
	return 0;
}
