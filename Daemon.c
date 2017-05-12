/*************************************************************************
	> File Name: Daemon.c
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Wed 10 May 2017 10:59:56 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
void my_daemon()
{
	//1.首先设置权限
	umask(0);

	//2.创建父子进程
	pid_t id = fork();

	if(id < 0)
	{//father
		exit(0);
	}
	else
	{//child
	}

	//setsid
	setsid();
	//更改目录为工作目录
	if(chdir("/") < 0)
	{	
		printf("chdir");
		return;
	}

	close(0);
	close(1);
	close(2);

	signal(SIGCHLD, SIG_IGN);
}
int main()
{
	my_daemon();

	while(1)
		;
}
