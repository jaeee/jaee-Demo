#include"LinkList.h"

void Funtest4()
{
	//Լɪ��
	//ð������
	Node link;
	pNode Head = &link;
	//��ʼ��
	InitLinkList(&Head);
	//ͷ��
	PushBack(&Head, 1);
	PushBack(&Head, 3);
	PushBack(&Head, 5);
	PushBack(&Head, 7);
	PushBack(&Head, 9);
	PrintLinkList(Head);
	pNode pre = Find(Head, 9);
	pre->next = Head;
	JosephCycle(&Head, 3);

}

void Funtest3()
{
	//ð������
	Node link;
	pNode Head = &link;
	//��ʼ��
	InitLinkList(&Head);
	//ͷ��
	PushBack(&Head, 1);
	PushBack(&Head, 3);
	PushBack(&Head, 5);
	PushBack(&Head, 7);
	PushBack(&Head, 9);
	PrintLinkList(Head);
	//BubbleSort(&Head);
	//PrintLinkList(Head);
	Node link2;
	pNode Head2 = &link2;
	//��ʼ��
	InitLinkList(&Head2);
	//ͷ��
	PushBack(&Head2, 2);
	PushBack(&Head2, 4);
	PushBack(&Head2, 6);
	PushBack(&Head2, 8);
	PrintLinkList(Head);
	Head2 = Merge(&Head, &Head2);
	PrintLinkList(Head2);
}

void Funtest2()
{
	Node link;
	pNode Head = &link;
	//��ʼ��
	InitLinkList(&Head);
	//ͷ��
	PushBack(&Head, 1);
	PushBack(&Head, 2);
	PushBack(&Head, 3);
	PushBack(&Head, 4);
	PrintLinkList(Head);
	//��������
	//ReverseLinkList(&Head);
	//PrintLinkList(Head);
	//�����ӡ
	ReversePrintLinkList(Head);
}


void FunTest()
{
	Node link;
	pNode Head = &link;
	//��ʼ��
	InitLinkList(&Head);
	//ͷ��
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

	//��ӡ
	PrintLinkList(Head);
	//βɾ������ֻ��һ���ڵ�ʱ��ɾ��
	PopBack(&Head);
	PrintLinkList(Head);

	//ͷ��
	PushFront(&Head, 6);
	PrintLinkList(Head);
	//ͷɾ
	PopFront(&Head, 6);
	PrintLinkList(Head);
	//����
	Find(Head, 6);
	 //ɾ��ָ��λ�ýڵ�
	Erase(&Head, Find(Head,2));
	PrintLinkList(Head);
	//ɾ��ָ������Ԫ�أ���һ�����֣�
	Remove(&Head, 5);
	PrintLinkList(Head);
	//ɾ������ָ��Ԫ��
	RemoveAll(&Head, 5);
	PrintLinkList(Head);
	//��ȡ�ڵ����
	printf("�ڵ������ %d\n", GetLinkNode(Head));
	//��������
	DestroyLinkList(&Head);
}

int main()
{
	FunTest();
	system("pause");
	return 0;
}