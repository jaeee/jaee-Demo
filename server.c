/*************************************************************************
	> File Name: client.c
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Tue 28 Feb 2017 04:58:12 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
int main()
{
	//printf("hello world\n");
	umask(0);
	if(mkfifo("./fifo",S_IFIFO|0666) < 0)
	{
		perror("mkfifo");
		return 1;
	}

	int fd = open("./fifo", O_RDONLY);
	if(fd < 0)
	{
		perror("open");
		return 2;
	}

	char buf[128];
	while(1)
	{
		ssize_t _s = read(fd, buf, sizeof(buf)-1);
		if(_s > 0)
		{
			buf[_s-1] = '\0';
			printf("client# %s\n",buf);
		}
		else if(_s == 0)
		{
			printf("client quit! I should quit!\n");
			break;
		}
		else
		{
			perror("read");
		}
	}

	close(fd);
	return 0;
}
