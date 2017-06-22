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

/***************������ӿ�**********************/
//1.�Ƚ�˳�����������ȱ�㣬˵˵���Ƿֱ���ʲô������ʹ�ã�
//2. ��β��ͷ��ӡ������
//3. ɾ��һ����ͷ������ķ�β�ڵ㣨���ܱ�������
//4. ����ͷ�������һ����ͷ�ڵ�ǰ����һ���ڵ�
//5. ������ʵ��Լɪ��(JosephCircle)
//6. ���� / ��ת������
//7. ����������ð������&��������
//8. �ϲ�������������, �ϲ�����Ȼ����
//9. ���ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ������
//10. ���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������
//11. �жϵ������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣿������ÿ���㷨��ʱ�临
//�Ӷ�&�ռ临�Ӷȡ�
//12. �ж����������Ƿ��ཻ�����ཻ���󽻵㡣����������������
//13. �ж����������Ƿ��ཻ�����ཻ���󽻵㡣������������ܴ������������桿
//14. ��������ĸ��ơ�һ�������ÿ���ڵ㣬��һ��ָ��nextָ��ָ����һ���ڵ㣬����һ
//��randomָ��ָ����������е�һ������ڵ����NULL������Ҫ��ʵ�ָ����������
//���ظ��ƺ��������
//15. ��������������������ͬ�����ݡ�void UnionSet(Node* l1, Node* l2);

//2.��β��ͷ��ӡ������
void ReversePrintLinkList(pNode pHead)
{
	assert(NULL != pHead);

	while (pHead->next != NULL)
	{
		ReversePrintLinkList(pHead->next);
		printf("%d -> ", pHead->_data);
		return;
	}
	printf("%d -> ", pHead->_data);

}

//3. ɾ��һ����ͷ������ķ�β�ڵ㣨���ܱ�������
void EraseNotTail(pNode pos)
{
	pNode del = pos->next;
	pos->_data = del->_data;
	pos->next = del->next;
	free(del);

}

//4. ����ͷ�������һ����ͷ�ڵ�ǰ����һ���ڵ�
void InsertFrontNode(pNode* pos, DataType data)
{
	assert(NULL != pos);
	pNode pNewNode = BuyNode(data);
	pNode pCur = *pos;
	pNewNode->next = pCur->next;
	pCur->next = pNewNode;
	DataType tmp = pCur->_data;
	pCur->_data = pNewNode->_data;
	pNewNode->_data = tmp;

}
//5.�������Լɪ�򻷣�ѭ��ɾ����K���ڵ�
//Լɪ�򻷣�Լɪ�����⣩��?����ѧ��Ӧ?���⣺
// ��֪n��?���Ա��1�� 2�� 3...n�ֱ��?��Χ����?��//Բ����Χ��
// �ӱ��Ϊk��?��ʼ����������m���Ǹ�?���У�������?��?�ִ�1��ʼ����������m���Ǹ�?
// �ֳ��У����˹����ظ���ȥ��ֱ��Բ����Χ��?ȫ�����С�
pNode JosephCycle(pNode* pHead, int num)//����ִ�е�ǰ�������������ȹ��ɻ�
{
	assert(pHead);
	pNode pCur = *pHead;
	int _num = num;
	while (pCur)
	{
		//��ֻ��һ���ڵ�ʱ���˳�
		if (pCur == pCur->next)
			break;

		while (--_num)
		{
			pCur = pCur->next;
		}
		pNode del = pCur->next;
		printf("ɾ�� ��%d \n", pCur->_data);
		pCur->_data = del->_data;
		pCur->next = del->next;
		free(del);
		_num = num;
	}
	*pHead = pCur;
	return pCur;
}

//6.���õ�����
//��ͷ�巽ʽ���������ӣ��Ӷ�����
void ReverseLinkList(pNode* pHead)
{
	pNode pCur = *pHead;
	pNode prev = pCur;
	pNode pNewNode = NULL;
	while (pCur != NULL)
	{
		pCur = pCur->next;
		prev->next = pNewNode;
		pNewNode = prev;
		prev = pCur;
	}
	*pHead = pNewNode;
}

//7.����������ð�����򣬿��ţ�
void BubbleSort(pNode* pHead)
{
	assert(NULL != pHead);
	pNode pCur = *pHead;
	pNode pPrev = NULL;

	int index1 = 0;
	int index2 = 0;

	while (pCur != pPrev)
	{
		while (pCur->next != pPrev)
		{
			if (pCur->_data > pCur->next->_data)
			{
				DataType tmp = pCur->_data;
				pCur->_data = pCur->next->_data;
				pCur->next->_data = tmp;
			}
			pCur = pCur->next;
		}
		pPrev = pCur;
		pCur = *pHead;
	}

}

//8.�ϲ�������������
pNode Merge(pNode* pHead1, pNode* pHead2)
{
	assert(pHead1&&pHead2);//1.���߾�Ϊ��

	//2.����һ��Ϊ��
	if (pHead1 != NULL && pHead2 == NULL)
	{
		return *pHead1;
	}
	else if (pHead1 == NULL && pHead2 != NULL)
	{
		return *pHead2;
	}
	pNode pCur1 = *pHead1;
	pNode pCur2 = *pHead2;
	pNode pNewHead = NULL;
	//����Ϊ����ϲ����ж�����ͷ��һ����Ϊ�������ͷ
	if (pCur1->_data < pCur2->_data)
	{
		pNewHead = pCur1;
		pCur1 = pCur1->next;
	}
	else
	{
		pNewHead = pCur2;
		pCur2 = pCur2->next;
	}
	pNode prev = pNewHead;
	while (pCur1&&pCur2)
	{
		if (pCur1->_data < pCur2->_data)
		{
			prev->next = pCur1;
			pCur1 = pCur1->next;
		}
		else
		{
			prev->next = pCur2;
			pCur2 = pCur2->next;
		}
		prev = prev->next;
	}
	if (NULL == pCur1)
	{
		prev->next = pCur2;
	}
	else
	{
		prev->next = pCur1;
	}
	return pNewHead;
}

//9. ���ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ������
pNode FindMidNode(pNode pHead)
{
	pNode pFast = pHead;
	pNode pSlow = pHead;

	while (pFast && pFast->next)
	{
		pFast = pFast->next->next;
		pSlow = pSlow->next;
	}
	return pSlow;
}

//10. ���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������
pNode FindKNode(pNode pHead, int k)
{
	pNode pCur = pHead;
	pNode pPre = pHead;
	if (GetLinkNode(pHead) < k)
	{
		return -1;
	}
	while (k--)
	{
		pCur = pCur->next;
	}
	while (pCur)
	{
		pCur = pCur->next;
		pPre = pPre->next;
	}
	return pPre;
}
#endif