#include"BinaryTree.h"

void Funtest1()
{
	int array[10] = { 1, 2, 3, -1, -1, 4, -1, -1, 5, 6 };
	//1, 2, 3, '#', '#', 4, '#', '#', 5, 6
	BinaryTree<int> bt(array, 10, -1);
	cout << "ǰ������� " ;
	bt.PreOrder();
	cout << "��������� " ;
	bt.InOrder();
	cout << "��������� " ;
	bt.PostOrder();
	cout << "��������� " ;
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
