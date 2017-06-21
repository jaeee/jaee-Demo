//void  InitList(PNode* pHead);//��ʼ��
//void  PrintList(PNode pHead);//��ӡ
//int  GetLinkNode(PNode pHead);//��ȡ�ڵ���
//void DestoryNode(PNode* pHead);//��������
//void  PushBack(PNode* pHead, DataType data);//β��
//void  PopBack(PNode* pHead);//βɾ
//void  PushFront(PNode* pHead, DataType data);//ͷ��
//void  PopFront(PNode* pHead);//ͷɾ
//PNode Find(PNode pHead, DataType data);//����data��λ��
//void  Erase(PNode* pHead, PNode pos);//ɾ��pos���Ľڵ�
//void  EraseNoTaiNode(PNode  pos);//��ͷָ��ɾ��,�ɲ��ÿ�����һ��������ݣ�ɾ����һ�����
//void  Insert(PNode pos, DataType data);//��pos�������һ���ڵ�
//void  Remove(PNode* pHead, DataType data);//ɾ�������еĵ�һ��data
//void  RemoveAll(PNode* pHead, DataType data);//ɾ�����������е�data
//void  Test();//����
//PNode  BuyNode(DataType data);//����PNode�ռ�洢data


#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef int DataType;

typedef struct LinkNode
{
	DataType _data;
	struct LinkNode* nedatat;
}Node,*pNode;

//Ϊ�½ڵ㿪�ٿռ�
pNode BuyNode(DataType data)
{
	pNode tmp = (pNode)malloc(sizeof(Node));
	tmp->_data = data;
	tmp->nedatat = NULL;
	return tmp;
}



//�����ʼ��
void InitLinkList(pNode* pHead)
{
	*pHead = NULL;
}
//��ӡ������
void PrintLinkList(pNode pHead)
{
	assert(NULL != pHead);
	pNode pCur = pHead;
	while (pCur != NULL)
	{
		printf("%d ->", pCur->_data);
		pCur = pCur->nedatat;
	}
	printf("\n");
}
//β��
void PushBack(pNode* pHead, DataType data)
{
	assert(NULL != pHead);
	pNode pCur = *pHead;
	//�жϽڵ��Ƿ�Ϊ��
	if (NULL == *pHead)
	{
		*pHead = BuyNode(data);
	}
	else
	{
		
		while (NULL != pCur->nedatat)
		{
			pCur = pCur->nedatat;
		}
		pCur->nedatat = BuyNode(data);
	}

}
//βɾ
void PopBack(pNode* pHead)
{
	assert(NULL != pHead);
	
	pNode pCur = *pHead;

	if (pCur == NULL)
	{
		printf("�����ǿյ�\n");
		return;
	}
	else if (NULL == pCur->nedatat)
	{
		free(pCur);
		*pHead = NULL;
	}
	else
	{
	    pCur = *pHead;
		pNode pre = NULL;
		while (NULL != pCur->nedatat)
		{
			pre = pCur;
			pCur = pCur->nedatat;
		}
		pre->nedatat = NULL;
		free(pCur);
		pCur = NULL;
	}
}
//ͷ��
void PushFront(pNode* pHead, DataType data)
{
	assert(NULL != pHead);
	pNode pCur;
	pCur = BuyNode(data);
	pCur->nedatat = *pHead;
	*pHead = pCur;
}
//ͷɾ
void PopFront(pNode* pHead, DataType data)
{
	assert(NULL != pHead);
	pNode pCur = *pHead;
	if (NULL == pCur)
	{
		printf("�����ǿյ�\n");
		return;
	}
	else if (NULL == pCur->nedatat)
	{
		free(pCur);
		*pHead = NULL;
	}
	else
	{
		pNode pre = *pHead;
		pre = pre->nedatat;
		*pHead = pre;
		free(pCur);
		pCur = NULL;
	}
}
pNode Find(pNode pHead, DataType data)
{
	pNode pCur = pHead;
	while (pCur)
	{
		if (pCur->_data == data)
		{
			printf("�ҵ��ˡ�����\n");
			return pCur;
		}
		else
		{
			pCur = pCur->nedatat;
		}
	}
	printf("û�������\n");
	return NULL;
}
//ɾ��ָ��λ�ýڵ㣨�Ƿ�Ϊͷ��㣡������
void Erase(pNode* pHead, pNode pos)
{
	assert(NULL != pHead);
	pNode pCur = *pHead;
	if (pCur == pos && pCur->nedatat == NULL)
	{
		free(pCur);
		*pHead = NULL;
		return;
	}
	else
	{
		while (pCur->nedatat != pos && pCur)
		{
			pCur = pCur->nedatat;
		}
		if (pCur)
		{
			pNode pre = pCur->nedatat;
			pCur->nedatat = pre->nedatat;
			free(pre);
		}
		else
		{
			printf("û���ҵ�\n");
		}
	}
}
//��ͷָ��ɾ��,�ɲ��ÿ�����һ��������ݣ�ɾ����һ�����
void EraseNoTail(pNode* pHead, pNode pos)
{
	pNode del = pos->nedatat;
	pos->_data = del->_data;
	pos->nedatat = del->nedatat;
	free(del);
	
}
//ɾ�������е�һ�����ֵ�data
void Remove(pNode* pHead, DataType data)
{
	assert(NULL != pHead);
	pNode pCur = *pHead;

	//�����ͷ���
	if (pCur->_data == data)
	{
		*pHead = pCur->nedatat;
		free(pCur);
		return;
	}
	else
	{
		while (pCur && pCur->nedatat->_data != data)
		{
			pCur = pCur->nedatat;
		}
		if (pCur)
		{
			pNode pre = pCur->nedatat;
			pCur->nedatat = pre->nedatat;
			free(pre);
			return;
		}
	}
	printf("û�������\n");
}

//ɾ������������dataֵ
void RemoveAll(pNode* pHead, DataType data)
{
	pNode pCur = *pHead;
	if (pCur->_data == data && pCur->nedatat == NULL)
	{
		free(pCur);
		*pHead = NULL;
		return;
	}
	pNode pre = *pHead;
	while (1)
	{
		//ע��pCur���п�λ��
		//while(pCur->_data != data && pCur)
		//��Ϊ���һ���ڵ� ����������жϷ�ʽ��һ��������ʱpCurΪNULLִ�����������쳣
		while (pCur && pCur->_data != data)
		{
			pre = pCur;
			pCur = pCur->nedatat;
		}
		if (pCur)
		{
			pre->nedatat = pCur->nedatat;
			free(pCur);
			pCur = pre->nedatat;
		}
		else
			return;
	}
}

int GetLinkNode(pNode pHead)
{
	pNode pCur = pHead;
	int number = 0;
	while (pCur != NULL)
	{
		pCur = pCur->nedatat;
		number++;
	}
	return number;
}
void DestroyLinkList(pNode* pHead)
{
	pNode del = *pHead;
	pNode pCur = *pHead;

	while (del)
	{
		del = *pHead;
		pCur = pCur->nedatat;
		*pHead = pCur;
		free(del);
	}
}
#endif