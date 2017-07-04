#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__
#include<iostream>
#include<queue>
using namespace std;
template<class T>
struct BinaryTreeNode
{
	T _value;
	BinaryTreeNode<T>* _left;
	BinaryTreeNode<T>* _right;

	BinaryTreeNode(const T& data)
		:_value(data)
		, _left(NULL)
		, _right(NULL)
	{}
};

template<class T>
class BinaryTree
{
public:
	BinaryTree()
		:_root(NULL)
	{}
	//�����������������
	BinaryTree(T* arr, int size)
	{
		int index = 0;
		_root = _CreateBinaryTree(arr, index, size);
	}
	//�������캯��
	BinaryTree(const BinaryTree<T>& t)
	{
		_root = _Copy(t._root);
	}
	//��ֵ����������
	BinaryTreeNode<T>& operator=(const BinaryTree<T>& t)
	{
		/*if (*this != t)
		{
			_root = _Copy(t._root);
		}*/
		swap(_root, t._root);//�ִ�д��
	}
	//��������
	~BinaryTree()
	{
		_Del(_root);
	}
	//ǰ����� ������� �������� ������� ��ڵ���� ��ȣ��߶ȣ�
	//ǰ����� 
	void PreOrder()
	{
		_PreOrder(_root);
		cout << endl;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	void PostOrder()
	{
		_PostOrder(_root);
		cout << endl;
	}
	void LevelOrder()
	{
		_LevelOrder(_root);
		cout << endl;
	}
	size_t Size()
	{
		size_t size = _Size(_root);
		return size;
	}
	size_t Depth()
	{
		size_t depth = _Depth(_root);
		return depth;
	}
protected:
	//��������������
	BinaryTreeNode<T>* _CreateBinaryTree(const T* arr, int& index, int size)
	{
		//����������� 
		//���������==���ݸ������˳�/��������Ϊ�գ�#��
		BinaryTreeNode<T>* root = NULL;
		if (index < size && arr[index] != -1)
		{
			//�ݹ鴴��
			root = new BinaryTreeNode<T>(arr[index]);
			root->_left = _CreateBinaryTree(arr, ++index, size);//�ȴ����������ڵ�
			root->_right = _CreateBinaryTree(arr, ++index, size);//�ٴ����������ڵ�
		}
		return root;
	}
	//��������
	BinaryTreeNode<T>* _Copy(const BinaryTreeNode<T>* root)
	{
		BinaryTreeNode<T>* tmp = NULL;
		if (root)
		{
			tmp = new BinaryTreeNode<T>(root->_value);
			tmp->_left = _Copy(root->_left);
			tmp->_right = _Copy(root->_right);
		}
		return tmp;
	}
	//���ٺ���
	void _Del(BinaryTreeNode<T>* root)
	{
		if (root)
		{
			_Del(root->_left);
			_Del(root->_right);
			delete root;
		}
	}
	//ǰ����� 
	void _PreOrder(BinaryTreeNode<T>* root)
	{
		if (root)
		{
			cout << root->_value << " ";
			_PreOrder(root->_left);
			_PreOrder(root->_right);
		}
	}
	//�������
	void _InOrder(BinaryTreeNode<T>* root)
	{
		if (root)
		{
			_InOrder(root->_left);
			cout << root->_value << " ";
			_InOrder(root->_right);
		}
	}
	//�������
	void _PostOrder(BinaryTreeNode<T>* root)
	{
		if (root)
		{
			_InOrder(root->_left);
			_InOrder(root->_right);
			cout << root->_value << " ";
		}
	}
	//�������
	void _LevelOrder(BinaryTreeNode<T>* root)
	{
		queue<BinaryTreeNode<T>*> q;
		q.push(root);
		while (!q.empty())
		{
			if (q.front())
			{
				BinaryTreeNode<T>* tmp = q.front();
				cout << tmp->_value << " ";
				if (tmp->_left)
					q.push(tmp->_left);
				if (tmp->_right)
					q.push(tmp->_right);
				q.pop();
			}
		}
	}
	//����ڵ����
	size_t _Size(BinaryTreeNode<T>* root)
	{
		if (root)
			return 0;
		return 1 + _Size(root->_left) + _Size(root->_right);
	}
	//������������
	size_t _Depth(BinaryTreeNode<T>* root)
	{
		int depth = 0;
		if (root)
		{
			int leftdepth = _Depth(root->_left);
			int rightdepth = _Depth(root->_right);
			depth = leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;
		}
		return depth;
	}
private:
	BinaryTreeNode<T>* _root;
};

#endif