/*************************************************************************
	> File Name: mysleep.c
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Tue 02 May 2017 08:20:40 PM CST
 ************************************************************************/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void handler(int sig)
{
	//do nothing...
}

int my_sleep(int time)
{
	struct sigaction act,oact;
	act.sa_handler = handler;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	
	sigaction(SIGALRM, &act, &oact);//注册信号处理函数，若未捕捉发送SIGALRM信号终止进程
	

	alarm(time);//设置闹钟，time秒后向系统发送SIGALRM信号，

	pause();//进程挂起

	int ret = alarm(0);//清空闹钟，返回值为上次闹钟剩余时间

	sigaction(SIGALRM, &oact, NULL);//恢复默认信号处理动作

	return ret;
}

int main()
{
	while(1)
	{
		unsigned int time = my_sleep(5);
		//printf("time = %d\n",time);
		printf("wake up...\n");
	}
	return 0;
}
