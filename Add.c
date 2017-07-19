/*************************************************************************
	> File Name: Add.c
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Fri 14 Jul 2017 01:21:56 PM CST
 ************************************************************************/

#include<stdio.h>

int ADD(int x, int y)
{
	int sum = 0;

	while( y != 0)
	{
		sum = x^y;//忽略进位计算两者和
		y = (x & y) << 1;
		x = sum;
	}
	return sum;
}

int main()
{
	int x = 3;
	int y = 5;
	printf(" %d + %d = %d \n",x,y,ADD(x ,y ));
	return 0;
}
