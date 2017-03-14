/*************************************************************************
	> File Name: sem.h
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Mon 13 Mar 2017 08:53:00 PM CST
 ************************************************************************/

//#pragma

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<sys/ipc.h>

#define KEY_PATH "."
#define PROJECT_ID 0x666

union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *__buf;
};

int create_sem(int nums);
int get_sem(int nums);
int init_sem(int sem_id, int which, int val);
int sem_P(int sem_id);
int sem_V(int sem_id);
int destroy_sem(int sem_id);

