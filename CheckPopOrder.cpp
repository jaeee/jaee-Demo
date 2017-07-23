/*************************************************************************
	> File Name: CheckPopOrder.cpp
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Sat 22 Jul 2017 02:29:40 PM CST
 ************************************************************************/

#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;
bool CheckPopOrder(int dataPush[], int dataPop[], int Push_len, int Pop_len)
{
	assert(dataPush && dataPop);
	if(Push_len != Pop_len && Push_len > 0)
	{
		return false;
	}

	stack<int> s;
	int i = 0;
	int j = 0;
	for( ; i < Push_len; i++)
	{
		s.push(dataPush[i]);
		while(s.size() > 0 && s.top() == dataPop[j])
		{
			s.pop();
			j++;
		}
	}
	return s.size() > 0 ? false : true;
}

int main()
{
	int dataPush[] = {1, 2, 3, 4, 5};
	int dataPop[] = {4, 5, 3, 2, 1};
	int dataPop2[] = {4, 5, 2, 3, 1};
	int len1 = sizeof(dataPush)/sizeof(dataPush[0]);
	int len2 = sizeof(dataPop)/sizeof(dataPop[0]);
	int len3 = sizeof(dataPop2)/sizeof(dataPop2[0]);
	cout<< CheckPopOrder(dataPush, dataPop, len1, len2) << endl;
	cout<< CheckPopOrder(dataPush, dataPop2, len1, len3) << endl;

	return 0;
}
