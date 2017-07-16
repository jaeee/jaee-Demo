/*************************************************************************
	> File Name: summary.c
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Fri 14 Jul 2017 12:55:54 AM CST
 ************************************************************************/

#include<stdio.h>
//递归版本
//int summary(int num)
//{
//	//if(num <= 0)
//	//	return 0;
//	//return num + summary(--num);
//	return num < 0 ? 0 : num + summary(num - 1);
//}

//利用&&
int summary(int num , int& sum)
{
	num && summary(num-1, sum);
	return (sum+=num);
}
int main()
{
	int num = 100;
	int sum = 0;
	printf("%d \n", summary(num, sum));
	return 0;
}
