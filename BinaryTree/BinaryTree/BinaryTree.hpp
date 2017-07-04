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
	//先序遍历建立二叉树
	BinaryTree(T* arr, int size)
	{
		int index = 0;
		_root = _CreateBinaryTree(arr, index, size);
	}
	//拷贝构造函数
	BinaryTree(const BinaryTree<T>& t)
	{
		_root = _Copy(t._root);
	}
	//赋值操作符重载
	BinaryTreeNode<T>& operator=(const BinaryTree<T>& t)
	{
		/*if (*this != t)
		{
			_root = _Copy(t._root);
		}*/
		swap(_root, t._root);//现代写法
	}
	//析构函数
	~BinaryTree()
	{
		_Del(_root);
	}
	//前序遍历 中序遍历 后续遍历 层序遍历 求节点个数 深度（高度）
	//前序遍历 
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
	//创建二叉树函数
	BinaryTreeNode<T>* _CreateBinaryTree(const T* arr, int& index, int size)
	{
		//先序遍历创建 
		//若插入个数==数据个数则退出/或者数据为空（#）
		BinaryTreeNode<T>* root = NULL;
		if (index < size && arr[index] != -1)
		{
			//递归创建
			root = new BinaryTreeNode<T>(arr[index]);
			root->_left = _CreateBinaryTree(arr, ++index, size);//先创建左子树节点
			root->_right = _CreateBinaryTree(arr, ++index, size);//再创建右子树节点
		}
		return root;
	}
	//拷贝函数
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
	//销毁函数
	void _Del(BinaryTreeNode<T>* root)
	{
		if (root)
		{
			_Del(root->_left);
			_Del(root->_right);
			delete root;
		}
	}
	//前序遍历 
	void _PreOrder(BinaryTreeNode<T>* root)
	{
		if (root)
		{
			cout << root->_value << " ";
			_PreOrder(root->_left);
			_PreOrder(root->_right);
		}
	}
	//中序遍历
	void _InOrder(BinaryTreeNode<T>* root)
	{
		if (root)
		{
			_InOrder(root->_left);
			cout << root->_value << " ";
			_InOrder(root->_right);
		}
	}
	//后序遍历
	void _PostOrder(BinaryTreeNode<T>* root)
	{
		if (root)
		{
			_InOrder(root->_left);
			_InOrder(root->_right);
			cout << root->_value << " ";
		}
	}
	//层序遍历
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
	//计算节点个数
	size_t _Size(BinaryTreeNode<T>* root)
	{
		if (root)
			return 0;
		return 1 + _Size(root->_left) + _Size(root->_right);
	}
	//计算二叉树深度
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