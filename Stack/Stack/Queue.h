//队列必须一端进行插入（队头）一端进行删除（队尾）

#ifndef __QUEUE_H__
#define __QUEUE_H__
#include<iostream>
#include<cassert>
using namespace std;

template<class T>
struct Node
{
	T _data;
	Node<T>* next;

	Node(const T& x)
		:_data(x)
		,next(NULL)
	{}
};

template<class T>
class Queue
{
public:
	Queue()
		:_Head(NULL)
		, _Tail(NULL)
	{}

	~Queue()
	{
		Clear();
	}

	Queue(const Queue<T>& q)
		:_Head(NULL)
		, _Tail(NULL)
	{
		Node<T>* pCur = q._Head;
		while (pCur)
		{
			/*_Head = new Node<T>*;
			_Head = pCur;
			_Head->_data = pCur->_data;*/
			Push(pCur->_data);
			pCur = pCur->next;
		}
	}
	//传统写法
	Queue<T>& operator=(const Queue<T>& q)
	{
		if (this != q)
		{
			Clear();
			Node<T>* pCur = q._Head;
			while (pCur)
			{
				/*_Head = new Node<T>*;
				_Head = pCur;
				_Head->_data = pCur->_data;*/
				Push(pCur->_data);
				pCur = pCur->next;
			}
		}
		return *this;
	}
	//现代写法
	Queue<T>& operator=(Queue<T> q)//这里先发生拷贝构造函数
	{
		//然后进行交换
		swap(_Head, q._Head);
		swap(_Tail, q._Tail);

		return *this;
	}
public:
	void Clear()
	{
		Node<T>* pCur = _Head;
		while (pCur)
		{
			Node<T>* Del = pCur;
			pCur = pCur->next;
			delete Del;
			Del = NULL;
		}
		_Head = NULL;
		_Tail = NULL;
	}
	void Push(const T& data)
	{
		if (_Head == NULL)
		{
			_Head = new Node<T>(data);
		}
		else
		{
			_Tail = new Node<T>(data);
			_Tail = _Tail->next;
		}
	}
	void Pop()
	{
		assert(_Head);

		//只有一个节点
		if (_Head == _Tail)
		{
			delete _Head;
			_Head = _Tail = NULL;
		}
		else
		{
			//一个以上
			Node<T>* temp = _Head->next;
			delete _Head;
			_Head = temp;
		}
	}
	
	T& Front()
	{
		return _Head->_data;
	}
	T& Back()
	{
		return _Tail->_data;
	}

	bool Empty()
	{
		if (_Head == NULL)
			return true;
		else
			return false;
	}

	size_t Size()
	{
		Node<T>* pCur = _Head;
		size_t count = 0;
		while (!Empty() && pCur)
		{
			count++;
			pCur = pCur->next;
		}
		return count;
	}
private:
	Node<T>* _Head;
	Node<T>* _Tail;
};
#endif