#include"LinkList.h"

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