/*************************************************************************
	> File Name: NumberOf1.cpp
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Sat 22 Jul 2017 03:27:00 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//int NumberOf1(int num)
//{
//	int FLAG = 1;
//	int count = 0;
//
//	while(FLAG)
//	{
//		if(num & FLAG)
//			count++;
//		FLAG <<= 1;
//	}
//	return count;
//}

int NumberOf1(int num)
{
	int count = 0;
	while(num)
	{
		num = num & (num - 1);
		count++;
	}
	return count;
}
int main()
{
	cout << NumberOf1(-10) << endl;

	return 0;
}
