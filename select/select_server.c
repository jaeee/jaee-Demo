/*************************************************************************
	> File Name: select.c
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Sun 04 Jun 2017 11:14:47 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>

int array_fds[1024];

static void Usage(char* proc)
{
	printf("Usage: %s [local_ip] [local_port]", proc);
}

int startup(char* _ip, int _port)
{
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0)
	{
		perror("socket");
		return 2;
	}

	int flg = 1;
	setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &flg, sizeof(flg));

	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(_port);
	local.sin_addr.s_addr = inet_addr(_ip);

	if(bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0)
	{
		perror("bind");
		return 3;
	}

	if(listen(sock, 5) < 0)
	{
		perror("listen");
		return 0;
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

	int listen_socket = startup(argv[1], atoi(argv[2]));

	fd_set rfds;
	int max_fd = 0;
	int array_size = sizeof(array_fds)/sizeof(array_fds[0]);
	array_fds[0] = listen_socket;
	int i = 0;
	for(i = 1; i < array_size; i++)
	{
		array_fds[i] = -1;
	}
	while(1)
	{
		max_fd = -1;
		struct timeval timeout = {0,0};
		FD_ZERO(&rfds);
		for(i = 0; i < array_size; i++)
		{
			if(array_fds[i] > 0)
			{
				FD_SET(array_fds[i], &rfds);
				if(array_fds[i] > max_fd)
				{
					max_fd = array_fds[i];
					//printf("i:%d,  %d\n",i,max_fd);
  				}
			}
		}

		switch(select(max_fd+1, &rfds, NULL,/*&rfds,*/ NULL, NULL))
		{
			case 0:
  				printf("timeout...\n");
				break; 
			case -1:
 				perror("select");
 				break; 
			default:
 				{ 
					//printf("select sus\n");
 					int k = 0;
					for(;k < array_size; k++)
					{
				  		if(array_fds[k] < 0)
							continue;

					   //	printf("k = %d, array_fds[k] : %d\n",k,array_fds[k]);
						if(k == 0 && FD_ISSET(array_fds[k], &rfds))
						{
					 	//	printf(" Accept\n");
				 			struct sockaddr_in client;
							socklen_t len = sizeof(client);
						    int new_sock = accept(array_fds[k], (struct sockaddr*)&client, &len);
							if(new_sock < 0)
							{
 								perror("accept");
								continue; 
							}
							else
							{
								printf("get a client : %s ,  %d \n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
								int j = 1;
								for(;j < array_size;j++)
								{
 					 				if(array_fds[j] < 0)  
									{
					 					array_fds[j] = new_sock;
 										break;
									}
								}
								if(j == array_size)
 				 					close(new_sock);
							//	printf("j:%d\n",j);
							//	printf("array_fds[1]:%d\n",array_fds[j]);
 			 	  			}
 			 			}
						else if(k != 0 && FD_ISSET(array_fds[k],&rfds))
						{
						//	printf("input\n");
					  	    char buf[10240];
					  	 	ssize_t s = read(array_fds[k], buf, sizeof(buf)-1);
					  	 	if(s > 0)
					  	 	{
	 				  	 		buf[s] = 0; 
 			 		  	 	 	printf("client say# %s \n", buf);
								write(array_fds[k], buf, strlen(buf));
					  	 	}
					  	 	else if(s == 0)
					  	 	{
	 				  	 	 	printf("client quit ...\n");
					  	 		close(array_fds[k]);
 					  	 		array_fds[k] = -1;
					  	 	}
					  	 	else
					  	 	{
								perror("read");
	 				  	 		close(array_fds[k]);
 			 		  	 	 	array_fds[k] = -1;
 					   	 	}  
					 	}
						else
						{
    					}
					 } 
					
				}
				break; 
		}
	}
	return 0;
}
