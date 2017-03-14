/*************************************************************************
	> File Name: semtest.c
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Mon 13 Mar 2017 08:55:14 PM CST
 ************************************************************************/


#include"sem.h"

int main()
{
	int sem_id = create_sem(1);
	init_sem(sem_id, 0, 1);

	pid_t id = fork();
	if(id < 0)
	{
		perror("fork");
		return -1;
	}
	else if(id == 0)
	{//child
		while(1)
		{
			sem_P(sem_id);

			printf("A");
			fflush(stdout);
			usleep(20000);
			usleep(23456);
			printf("A");

			sem_V(sem_id);
		}
	}
	else
	{//father
		while(1)
		{
			sem_P(sem_id);

			printf("B");
			fflush(stdout);
			usleep(29633);
			usleep(23456);
			printf("B");

			sem_V(sem_id);
		}
	}

	destroy_sem(sem_id);
	return 0;
}

