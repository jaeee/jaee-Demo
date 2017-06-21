#include"SeqList_D.h"

void FunTest1()
{
	SeqList _list;
	InitSeqList(&_list);

	//尾插
	Push_back(&_list, 1);
	Push_back(&_list, 2);
	Push_back(&_list, 3);
	Push_back(&_list, 4);
	Push_back(&_list, 5);
	Push_back(&_list, 6);
	Push_back(&_list, 2);
	Push_back(&_list, 8);
	Push_back(&_list, 2);

	PrintSeqList(_list);
	//尾删
	Pop_back(&_list);
	PrintSeqList(_list);
	//头插
	Push_Front(&_list, 0);
	PrintSeqList(_list);
	//头删
	Pop_Front(&_list);
	PrintSeqList(_list);
	//指定位置插入
	Insert(&_list, 6, 2);
	PrintSeqList(_list);
	//删除指定元素
	Remove(&_list, 2);
	PrintSeqList(_list);
	//删除所有指定元素
	RemoveAll(&_list, 2);
	PrintSeqList(_list);
	//逆置元素
	/*Reverse(&_list);
	PrintSeqList(_list);*/
	//二分查找
	BinarySearch(&_list, 5);
	//冒泡排序
	SortSeqList(&_list);
	PrintSeqList(_list);
	//销毁
	DestroySeqList(&_list);
}


int main()
{
	FunTest1();
	system("pause");
	return 0;
}