#include"LinkList.h"

void Funtest2()
{
	Node link;
	pNode Head = &link;
	//初始化
	InitLinkList(&Head);
	//头插
	PushBack(&Head, 1);
	PushBack(&Head, 2);
	PushBack(&Head, 3);
	PushBack(&Head, 4);
	PrintLinkList(Head);
	//链表逆置
	//ReverseLinkList(&Head);
	//PrintLinkList(Head);
	//逆序打印
	ReversePrintLinkList(Head);
}


void FunTest()
{
	Node link;
	pNode Head = &link;
	//初始化
	InitLinkList(&Head);
	//头插
	PushBack(&Head, 1);
	PushBack(&Head, 2);
	PushBack(&Head, 3);
	PushBack(&Head, 4);
	PushBack(&Head, 5);
	PushBack(&Head, 5);
	PushBack(&Head, 7);
	PushBack(&Head, 5);
	PushBack(&Head, 5);
	PushBack(&Head, 8);

	//打印
	PrintLinkList(Head);
	//尾删、测试只有一个节点时的删除
	PopBack(&Head);
	PrintLinkList(Head);

	//头插
	PushFront(&Head, 6);
	PrintLinkList(Head);
	//头删
	PopFront(&Head, 6);
	PrintLinkList(Head);
	//查找
	Find(Head, 6);
	 //删除指定位置节点
	Erase(&Head, Find(Head,2));
	PrintLinkList(Head);
	//删除指定数字元素（第一个出现）
	Remove(&Head, 5);
	PrintLinkList(Head);
	//删除所有指定元素
	RemoveAll(&Head, 5);
	PrintLinkList(Head);
	//获取节点个数
	printf("节点个数： %d\n", GetLinkNode(Head));
	//销毁链表
	DestroyLinkList(&Head);
}

int main()
{
	FunTest();
	system("pause");
	return 0;
}