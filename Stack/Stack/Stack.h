#ifndef __STACK_H__
#define __STACK_H__

#include<iostream>
#include<cassert>
using namespace std;
//˳��ջ ���

template <typename T>
class Stack
{
public:
	Stack(size_t capacity = 5)
		:_size(0),
		_capacity(5)
	{
		_capacity = (capacity > _capacity) ? capacity : _capacity;
		_array = new T[_capacity];
	}

	Stack(const Stack<T>& s)
	{
		_array = new T[s._capacity];
		_size = s._size;
		__capacity = s._capacity;

		for (size_t index = 0; index < _size; index++)
		{
			_array[index] = s._array[index];
		}
	}
	//�������� ��ͨ��
	/*Stack<T>& operator=(const Stack<T>& s)
	{
		_array = new T[s._capacity];
		_size = s._size;
		__capacity = s._capacity;

		for (size_t index = 0; index < _size; index++)
		{
			_array[index] = s._array[index];
		}
		return *this;
	}*/
	//����
	Stack<T>& operator=(const Stack<T>& s)
	{
		if (*this != s)
		{
			Stack temp(s);
			swap(_array, temp._array);
			_size = s._size;
			_capacity = s._capacity;
		}
		return *this;
	}

	~Stack()
	{
		if (Empty())
		{
			delete[] _array;
			_size = 0;
			_capacity = 0;

		}
	}

public:
	//ѹջ
	void Push(const T data)
	{
		CheckCapacity();
		_array[_size++] = data;
	}
	void Pop()
	{
		--_size;
	}
	Stack<T> Top()
	{
		assert(!Empty());
		//����ջ��Ԫ��
		cout << _array[_size-1] << endl;
		return _array[_size-1];
	}
	size_t Length() const
	{
		return _size;
	}
	void Print()
	{
		assert(!Empty());
		for (int index = 0; index < _size; index++)
		{
			cout << _array[index] << "  ";
		}
	}
private:
	bool Empty()
	{
		return (_size == 0);
	}

	//�������
	void CheckCapacity()
	{
		if (_size >= _capacity)
		{
			T* temp = new T[2 * _capacity];
			for (int index = 0; index < _size; index++)
			{
				temp[index] = _array[index];
			}
			_array = temp;
			_capacity *= 2;
		}
	}
private:
	T* _array;
	size_t _size;
	size_t _capacity;

};

#endif