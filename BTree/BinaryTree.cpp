#include"BinaryTree.h"

void Funtest1()
{
	int array[10] = { 1, 2, 3, -1, -1, 4, -1, -1, 5, 6 };
	//1, 2, 3, '#', '#', 4, '#', '#', 5, 6
	BinaryTree<int> bt(array, 10, -1);
	cout << "前序遍历： " ;
	bt.PreOrder();
	cout << "中序遍历： " ;
	bt.InOrder();
	cout << "后序遍历： " ;
	bt.PostOrder();
	cout << "层序遍历： " ;
	bt.LevelOrder();

	cout << "size: " << bt.Size() << endl;
	cout << "depth: " << bt.Depth() << endl;	
}

int main()
{
	Funtest1();
	system("pause");
	return 0;
}
