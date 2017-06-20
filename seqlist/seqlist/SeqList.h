//void InitSeqlist(pSeqList plist);//��ʼ��
//void PrintSeqlist(pSeqList plist);//��ӡ˳���
//void PushBack(pSeqList plist, DataType x);//β��
//void PopBack(pSeqList plist);//βɾ
//void PushFront(pSeqList plist, DataType x);//ͷ��
//void PopFront(pSeqList plist);//ͷɾ
//void Insert(pSeqList plist, int pos, DataType x);//ָ��λ�ò���
//void Remove(pSeqList plist, DataType x);//ָ��ɾ��
//void RemoveAll(pSeqList plist, DataType x);
//int Find(pSeqList plist, DataType x);//����
//void ReverseList(pSeqList plist);//����
//void SortList(pSeqList plist);//����
//void BinarySearch(pSeqList plist, DataType x);//���ֲ���



#ifndef _SEQ_LIST_H_
#define _SEQ_LIST_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
typedef int DataType;
#define MAX 100 
typedef struct seqlist
{
	DataType data[MAX];
	int _size;
}SeqList, *pSeqList;

//��ʼ��
void InitSeqList(pSeqList plist)
{
	assert(NULL != plist);
	memset(plist->data, 0, sizeof(DataType)*MAX);
	plist->_size = 0;
}

//��ӡ˳���
void PrintSeqList(SeqList plist)
{
	int i = 0;
	if (plist._size == 0)
	{
		printf("SeqList id empty...\n");
		return;
	}
	for (i = 0; i < plist._size; i++)
	{
		printf("%d ", plist.data[i]);
	}
	printf("\n");
}
//β��
void Push_back(pSeqList plist, DataType x)
{
	assert(NULL != plist);
	
	if (plist->_size == MAX)
	{
		printf("SeqList if full!!!\n");
		return;
	}
	plist->data[plist->_size++] = x;
}
//βɾ
void Pop_back(pSeqList plist)
{
	assert(NULL != plist);
	if (plist->_size == 0)
	{
		printf("SeqList is empty!!!\n");
		return;
	}
	plist->_size--;
}
void Push_Front(pSeqList plist, DataType x)
{
	assert(NULL != plist);
	if (plist->_size == MAX)
	{
		printf("SeqList if full!!!\n");
		return;
	}
	int index = plist->_size;
	for (; index > 0; index--)
	{
		plist->data[index] = plist->data[index - 1];
	}
	plist->data[index] = x;
	plist->_size++;
}
void Pop_Front(pSeqList plist)
{
	assert(NULL != plist);
	if (plist->_size == 0)
	{
		printf("SeqList is empty!!!\n");
		return;
	}
	int index = 0;
	for (; index < plist->_size; index++)
	{
		plist->data[index] = plist->data[index + 1];
	}
	plist->_size--;
}
//ָ��λ�ò���
void Insert(pSeqList plist, DataType x, int pos)
{
	assert(NULL != plist);
	if ((pos >= MAX) && pos < 0)
	{
		printf("position is error!!!\n");
		return;
	}
	int index = plist->_size;
	for (; index>pos; index--)
	{
		plist->data[index] = plist->data[index - 1];
	}
	plist->data[index] = x;
	plist->_size++;
}
//ɾ��ָ������
void Remove(pSeqList plist, DataType x)
{
	assert(NULL != plist);
	if (plist->_size == 0)
	{
		printf("SeqList is empty!!!\n");
		return;
	}
	int isFind = Find(*plist, x);
	if (isFind > 0)
	{
		int index = isFind;
		for (; index < plist->_size; index++)
		{
			plist->data[index] = plist->data[index + 1];
		}
		plist->_size--;
	}
	else
		printf("not exist\n");
	
}
//ɾ��ָ������Ԫ��
void RemoveAll(pSeqList plist, DataType x)
{
	assert(NULL != plist);
	if (plist->_size == 0)
	{
		printf("SeqList is empty!!!\n");
		return;
	}
	int isFind = 0;
	while ((isFind = Find(*plist, x))!=-1)
	{
		int index = isFind;
		for (; index < plist->_size; index++)
		{
			plist->data[index] = plist->data[index + 1];
		}
		plist->_size--;
	}
}
int Find(SeqList plist, DataType x)
{
	int index = 0;
	for (; index < plist._size; index++)
	{
		if (x == plist.data[index])
			return index;
	}
	return -1;
}
//����дð������
void SortSeqList(pSeqList plist)
{
	assert(NULL != plist);
	int index = 0;
	int index2 = 0;
	int flag = 0;

	for (; index < plist->_size - 1;index++)
	{
		flag = 1;
		for (index2 = 0; index2 < plist->_size - index - 1; index2++)
		{
			if (plist->data[index2] > plist->data[index2 + 1])
			{
				DataType tmp = plist->data[index2];
				plist->data[index2] = plist->data[index2 + 1];
				plist->data[index2 + 1] = tmp;
				flag = 0;
			}
		}
		if (flag == 1)
			return;
	}
}
//����
void Reverse(pSeqList plist)
{
	assert(NULL != plist);
	int start = 0;
	int end = plist->_size - 1;

	while (start != end)
	{
		DataType tmp = plist->data[start];
		plist->data[start] = plist->data[end];
		plist->data[end] = tmp;
		start++;
		end--;
	}
}
void BinarySearch(pSeqList plist, DataType x)
{
	assert(NULL != plist);
	int left = 0;
	int right = plist->_size - 1;
	int mid = (left + right) / 2;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (plist->data[mid] == x)
		{
			printf("�ҵ��ˣ��ǵ� %d ��\n", mid + 1);
			return 0;
		}
		else if (x > plist->data[mid])
		{
			left = mid + 1;
		}
		else if (x < plist->data[mid])
		{
			right = mid - 1;
		}
	}

	printf("û�������\n");
}




#endif