#include"Stack.h"

void Funtest1()
{
	Stack<int> s1(3);//初始容量小于要求的初始值
	Stack<int> s2(7);//大于等于初始值

	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	s1.Push(5);
	//容量不足时
	s1.Push(6);
	s1.Push(7);
	s1.Print();
	s1.Pop();
	s1.Pop();
	cout << endl;
	s1.Top();
	
}

int main()
{
	Funtest1();
	system("pause");
	return 0;
}