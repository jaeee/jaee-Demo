/*************************************************************************
	> File Name: sem.c
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Mon 13 Mar 2017 08:53:15 PM CST
 ************************************************************************/

#include"sem.h"


int create_sem(int nums)
{
	key_t _key = ftok(KEY_PATH, PROJECT_ID);
	return semget(_key, nums, IPC_CREAT|IPC_EXCL|0644);
}

int get_sem(int nums)
{
	key_t _key = ftok(KEY_PATH, PROJECT_ID);
	return semget(_key, nums, IPC_CREAT);
}

static int op_sem(int sem_id, int op)
{
	struct sembuf sem;
	//memset(&sem, '\0', sizeof(sem));
	sem.sem_num = 0;
	sem.sem_op = op;
	sem.sem_flg = 0;

	return semop(sem_id, &sem, 1);
}

int init_sem(int sem_id, int which, int val)
{
	union semun un;
	un.val = val;
	return semctl(sem_id, which, SETVAL,un);
}

int sem_P(int sem_id)
{
	return op_sem(sem_id, -1);
}

int sem_V(int sem_id)
{
	return op_sem(sem_id, 1);
}

int destroy_sem(int sem_id)
{
	return semctl(sem_id, 0, IPC_RMID);
}
