#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class String
{
public:
	//���캯��
	String(char* pStr = "")
	{
		if (NULL == pStr)
		{
			_pStr = new char[1];
			*_pStr = '\0';
		}
		else
		{
			_pStr = new char[strlen(pStr) + 1];
			strcpy(_pStr, pStr);
		}
	}

	////�������캯��1 ����
	//String(const String& pStr)
	//	:_pStr(NULL)
	//{
	//	String temp(pStr._pStr);
	//	swap(_pStr, temp._pStr);
	//}

	//�������캯��2 ��ͨ��

	String(String& pStr)
		:_pStr(new char[strlen(pStr._pStr)+1])
	{
		strcpy(_pStr, pStr._pStr);
	}

	////��ֵ���������1
	//String& operator=(const String& pStr)
	//{
	//	if (this != &pStr)
	//	{
	//		String temp(pStr._pStr);
	//		swap(_pStr, temp._pStr);
	//	}
	//	return *this;
	//}

	//��ֵ���������2
	String& operator=(const String& pStr)
	{
		if (this != &pStr)
		{
			//��ֹnew�����ڴ�ʧ�ܣ���ʧԭ���ڴ�
			char* ptr = new char[strlen(pStr._pStr) + 1];
			strcpy(ptr, pStr._pStr);
			delete[]_pStr;
			_pStr = ptr;
		}
		return *this;
	}


	//��������
	~String()
	{
		if (NULL != this)
		{
			delete[]_pStr;
			_pStr = NULL;
		}
	}

	friend ostream& operator<<(ostream& _cout, const String& pStr);
private:
	char* _pStr;
};


ostream& operator<<(ostream& _cout, const String& pStr)
{
	_cout << pStr._pStr;
	return _cout;
}

void Funtest()
{
	String s1("hehe");
	cout << s1 << endl;
	String s2;
	s2 = s1;
	cout << s2 << endl;

	String s3(s1);
	cout << s3 << endl;

}
void Funtest2()
{
	String s1("hello");
	String s2(s1);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << "##################" << endl;

	String s3("world");
	cout << s3 << endl;
	s3 = s1;
	cout << s3 << endl;
	cout << "##################" << endl;
}

int main()
{
	Funtest2();
	system("pause");
	return 0;
}
