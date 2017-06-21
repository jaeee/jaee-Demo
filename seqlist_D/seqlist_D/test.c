#include"SeqList_D.h"

void FunTest1()
{
	SeqList _list;
	InitSeqList(&_list);

	//β��
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
	//βɾ
	Pop_back(&_list);
	PrintSeqList(_list);
	//ͷ��
	Push_Front(&_list, 0);
	PrintSeqList(_list);
	//ͷɾ
	Pop_Front(&_list);
	PrintSeqList(_list);
	//ָ��λ�ò���
	Insert(&_list, 6, 2);
	PrintSeqList(_list);
	//ɾ��ָ��Ԫ��
	Remove(&_list, 2);
	PrintSeqList(_list);
	//ɾ������ָ��Ԫ��
	RemoveAll(&_list, 2);
	PrintSeqList(_list);
	//����Ԫ��
	/*Reverse(&_list);
	PrintSeqList(_list);*/
	//���ֲ���
	BinarySearch(&_list, 5);
	//ð������
	SortSeqList(&_list);
	PrintSeqList(_list);
	//����
	DestroySeqList(&_list);
}


int main()
{
	FunTest1();
	system("pause");
	return 0;
}