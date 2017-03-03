#pragma once
#include<iostream>
#include <vector>
#include<assert.h>
using namespace std;
template<class T>
class Heap
{
public:
	Heap()
	{}

	Heap(const T* array, size_t size)
		//:_array(array, size)
	{
		for (size_t i = 0; i < size; ++i)
		{
			_array.push_back(array[i]);
		}

		int begin = (_array.size() - 1) / 2;
		while (begin--)
		{
			AdjustDown(begin);
		}
		/*for (; begin >= 0; --begin)
		{
			AdjustUp(begin);
		}*/
	}

	Heap(vector<T>& array)
	{}
//protected:
	void AdjustDown(int root)
	{
		int left = root * 2 + 1;
		int right = left + 1;
		int min = left;
		while (left < _array.size())
		{
			//找左右孩子里面最小的那个

			
			if ((right < _array.size()) && (_array[right] < _array[left]))
			{
				min = right;
			}

			//min小则与根节点交换
			if (_array[min] < _array[root])
			{
				swap(_array[root], _array[min]);
				root = min;
				left = root * 2 + 1;
				right = left + 1;
				min = left;
			}
			else
			{
				//跳出循环
				break;
			}
		}
	}

	//void AdjustUp(int child)
	//{
	//	int root = (child - 1) / 2;

	//	while (root >= 0)
	//	{
	//		//int root = (child - 1) / 2;
	//		if (_array[root] > _array[child])
	//		{
	//			swap(_array[root], _array[child]);
	//			child = root;
	//			root = (child - 1) / 2;
	//		}
	//		else
	//		{
	//			break;
	//		}
	//	}
	//}

	void Insert(const T& x)
	{
		_array.push_back(x);
		int root = (_array.size()/2) - 1;

		int temp = _array.size() - 1;

		while (temp > root)
		{
			if (_array[temp] < _array[root])
			{
				swap(_array[temp], _array[root]);
				temp = root;
				root = (root - 1) / 2;
			}
			else
			{
				return;
			}
		}
	}

	void Erase()
	{
		swap(_array[0], _array[_array.size() - 1]);
		_array.pop_back();
		AdjustDown(0);
	}

	void print()
	{
		for (size_t i = 0; i < _array.size(); ++i)
		{
			cout << _array[i] << "->";
		}

		cout << endl;
	}

	void sort(T* arr, int size)
	{
		assert(arr);

		for (int i = 0; i < size; i++)
		{
			_array.push_back(arr[i]);
		}

		int root = (_array.size() - 1) / 2;
		while (root--)
		{
			AdjustDown(root);
		}
	}
private:
	vector<T> _array;
};

void TestHeap()
{
	//int array[10] = { 10, 16, 18, 12, 11, 13, 15, 17, 14, 19 };
	int arr[9] = { 16, 18, 12, 11, 13, 15, 17, 14, 19 };

	Heap<int> hp1(arr, 9);
	//hp1.sort(arr, 9);
	hp1.Insert(9);
	hp1.print();
	hp1.Erase();
}