/*************************************************************************
	> File Name: myshell.c
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Wed 22 Feb 2017 10:17:58 PM CST
 ************************************************************************/
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>

int main()
{
	while(1)
	{	
	char cmd[128];
	printf("[liumin@bogon 2_22]$ ");
	//getuid() getpwuid...
	fflush(stdout);
    sleep(1);

	ssize_t _s = read(0, cmd, sizeof(cmd)-1);
	if(_s > 0)
	{
		cmd[_s-1 ] = '\0';
	}
	else 
	{
		perror("read");
		return 1;
	}
	char *_argv[32];
	_argv[0]= cmd;
	int i =1;

	char *start= cmd;
	while(*start)
	{
		if(isspace(*start))
		{
			*start = '\0';
			start++;
			_argv[i]= start;
			i++;
			//printf("i = %d",i);
			continue;
		}
		start++;
	}
	//printf("NULL :i = %d",i);
	_argv[i] = NULL;


	pid_t id=fork();
	if(id < 0)
	{
		perror("fork");
	}
	else if( id == 0)
	{
        execvp(_argv[0],_argv);
	}
	else
	{
		int status = 0;
		pid_t ret = waitpid(id, &status, 0);
		if(ret > 0&& WIFEXITED(status))
		{
			printf("exit code : %d\n",WEXITSTATUS(status));
		}
		else
		{
			perror("waitpid");
		}
	}
	}
    
	return 0;
}
