#include"Stack.h"

void Funtest1()
{
	Stack<int> s1(3);//��ʼ����С��Ҫ��ĳ�ʼֵ
	Stack<int> s2(7);//���ڵ��ڳ�ʼֵ

	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	s1.Push(5);
	//��������ʱ
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