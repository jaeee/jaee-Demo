#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//
//class String
//{
//public:
//	String(char* pStr = "")
//		:_pStr(new char[strlen(pStr)+1])
//	{
//		strcpy(_pStr, pStr);
//		_pCount++;
//	}
//
//	String(String& s)
//		:_pStr(s._pStr)
//	{
//		_pCount++;
//	}
//	//赋值运算符重载只有面对同一个对象，无需重写
//	~String()
//	{
//		if (--_pCount == 0)
//		{
//			delete[] _pStr;
//		}
//	}
//private:
//	char* _pStr;
//	static int _pCount;
//};

//int String::_pCount = 0;
//
//使用单独内存的引用计数
//class String
//{
//public:
//	String(char* pStr = "")
//		:_pStr(new char[strlen(pStr) + 1])
//		,_pCount(new int(1))
//	{
//		strcpy(_pStr, pStr);
//	}
//
//	String(String& s)
//		:_pStr(s._pStr)
//	{
//		_pCount++;
//	}
//	String& operator=(const String& s)
//	{
//		if (_pStr != s._pStr)
//		{
//			Delete();
//			_pStr = s._pStr;
//			_pCount = s._pCount;
//			_pCount++;
//		}
//		return *this;
//	}
//	~String()
//	{
//		Delete();
//	}
//private:
//	void Delete()
//	{
//		if (0 == (--(*_pCount)))
//		{
//			delete[] _pStr;
//			delete _pCount;
//		}
//	}
//private:
//	char* _pStr;
//	int* _pCount;
//};

//在同一空间中使用引用计数—— _pCount ====(int*)(_pStr-4)
class String
{
public:
	String(char* pStr = "")
		:_pStr(new char[strlen(pStr) + 5])
	{
		*_pStr = 1;
		_pStr -= 4;
		strcpy(_pStr, pStr);
	}

	String(String& s)
		:_pStr(s._pStr)
	{
		//++(*((int*)(_pStr - 4)));
		++GetRefCount();
	}
	String& operator=(const String& s)
	{
		if (_pStr != s._pStr)
		{
			Delete();
			_pStr = s._pStr;
			//_pCount = s._pCount;
			//_pCount++;
			++GetRefCount();

		}
		return *this;
	}
	~String()
	{
		Delete();
	}
private:
	void Delete()
	{
		if (0 == (--(GetRefCount())))
		{
			delete[] (_pStr-4);
			//delete _pCount;
		}
	}
	int& GetRefCount()
	{
		return *((int*)(_pStr - 4));
	}
private:
	char* _pStr;
};

void fun1()
{
	String s1("hello");
	String s2(s1);
	s2 = s1;
}


void fun2()
{
	String s1("hello");
	String s2(s1);
	
	String s3("world");
	String s4(s3);

	s3 = s2;
}

void fun3()
{
	String s1("hello");
	String s2("world");
	s2 = s1;
}
int main()
{
	fun1();
	fun2();
	fun3();
	return 0;
}