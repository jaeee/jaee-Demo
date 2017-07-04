#include"BinaryTree.hpp"

void Funtest1()
{
	int array[9] = { 1, 2, 4, -1, 7, -1, 3, 5, 6 };
	BinaryTree<int> bt(array, 9);
	bt.PreOrder();
	bt.InOrder();
	bt.PostOrder();
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