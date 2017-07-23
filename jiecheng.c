/*************************************************************************
	> File Name: jiecheng.c
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Sun 23 Jul 2017 09:20:34 AM CST
 ************************************************************************/

#include<stdio.h>

int JieCheng(int num)
{
	int count = 0;
	int i = 1;
	int j = 0;
	for(; i < num; i++)
	{
		j = i;
		while(j % 5 == 0)
		{
			count++;
			j /= 5;
		}
	}
	return count;
}

int main()
{
	printf(" %d ", JieCheng(5));
	return 0;
}
