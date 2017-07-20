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
	struct LinkNode* next;
}Node,*pNode;

//Ϊ�½ڵ㿪�ٿռ�
pNode BuyNode(DataType data)
{
	pNode tmp = (pNode)malloc(sizeof(Node));
	tmp->_data = data;
	tmp->next = NULL;
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
		pCur = pCur->next;
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
		
		while (NULL != pCur->next)
		{
			pCur = pCur->next;
		}
		pCur->next = BuyNode(data);
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
	else if (NULL == pCur->next)
	{
		free(pCur);
		*pHead = NULL;
	}
	else
	{
	    pCur = *pHead;
		pNode pre = NULL;
		while (NULL != pCur->next)
		{
			pre = pCur;
			pCur = pCur->next;
		}
		pre->next = NULL;
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
	pCur->next = *pHead;
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
	else if (NULL == pCur->next)
	{
		free(pCur);
		*pHead = NULL;
	}
	else
	{
		pNode pre = *pHead;
		pre = pre->next;
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
			pCur = pCur->next;
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
	if (pCur == pos && pCur->next == NULL)
	{
		free(pCur);
		*pHead = NULL;
		return;
	}
	else
	{
		while (pCur->next != pos && pCur)
		{
			pCur = pCur->next;
		}
		if (pCur)
		{
			pNode pre = pCur->next;
			pCur->next = pre->next;
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
	pNode del = pos->next;
	pos->_data = del->_data;
	pos->next = del->next;
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
		*pHead = pCur->next;
		free(pCur);
		return;
	}
	else
	{
		while (pCur && pCur->next->_data != data)
		{
			pCur = pCur->next;
		}
		if (pCur)
		{
			pNode pre = pCur->next;
			pCur->next = pre->next;
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
	if (pCur->_data == data && pCur->next == NULL)
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
			pCur = pCur->next;
		}
		if (pCur)
		{
			pre->next = pCur->next;
			free(pCur);
			pCur = pre->next;
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
		pCur = pCur->next;
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
		pCur = pCur->next;
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
void ReversePrint(pNode pHead)
{
	assert(pHead);

	if (pHead->next != NULL)
		ReversePrint(pHead->next);

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


//�ݹ� ͬ����ԭ�� �õݹ�����ô�����Ӽ��
pNode _Merge(pNode pHead1, pNode pHead2)
{
	//һ����pNewHead��ǰ�棬���ױ�����ʾ����δ���壩
	pNode pNewHead = NULL;
	if (pHead1 == NULL)
		return pHead1;
	if (pHead2 == NULL)
		return pHead2;

	if (pHead1->_data < pHead2->_data)
	{
		pNewHead = pHead1;
		pNewHead->next = _Merge(pHead1->next, pHead2);
	}
	else
	{
		pNewHead = pHead2;
		pNewHead->next = _Merge(pHead1, pHead2->next);
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

//11. �жϵ������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣿������ÿ���㷨��ʱ�临
//�Ӷ�&�ռ临�Ӷȡ�
//12. �ж����������Ƿ��ཻ�����ཻ���󽻵㡣����������������
//13. �ж����������Ƿ��ཻ�����ཻ���󽻵㡣������������ܴ������������桿
//14. ��������ĸ��ơ�һ�������ÿ���ڵ㣬��һ��ָ��nextָ��ָ����һ���ڵ㣬����һ
//��randomָ��ָ����������е�һ������ڵ����NULL������Ҫ��ʵ�ָ����������
//���ظ��ƺ��������
//15. ��������������������ͬ�����ݡ�void UnionSet(Node* l1, Node* l2);


//11. �жϵ������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣿������ÿ���㷨��ʱ�临
//�Ӷ�&�ռ临�Ӷȡ�
//1)�жϴ���
pNode CheckCircle(pNode pHead)
{
	//�ж��Ƿ�ֻ��һ���ڵ�
	if (pHead->next == NULL)
	{
		return NULL;
	}
	pNode pFast = pHead;
	pNode pSlow = pHead;

	while (pFast)
	{
		pFast = pFast->next->next;
		pSlow = pSlow->next;
		if (pFast == pSlow)
			return pFast;
	}
	return NULL;
}
//2���󻷵ĳ���
int GetCircleLength(pNode Meet)
{
	pNode pCur = Meet;
	int len = 0;
	do
	{
		pCur = pCur->next;
		len++;
	} while (pCur != Meet);
	return len;
}
//3)�󻷵���ڵ� x = nl-y
pNode GetCircleEnterNode(pNode pHead, pNode Meet)
{
	pNode pFast = Meet;//��Ĵ������㿪ʼ��
	pNode pSlow = pHead;

	while (pFast != pSlow)
	{
		pSlow = pSlow->next;
		pFast = pFast->next->next;
	}
	return pFast;
}

//12. �ж����������Ƿ��ཻ�����ཻ���󽻵㡣����������������
//�����ж��Ƿ��ཻ
int Check_Cross(pNode pHead1, pNode pHead2)
{
	pNode pList1 = pHead1;
	pNode pList2 = pHead2;
	if (pHead1 == NULL || pHead2 == NULL)
	{
		return 1;
	}
	while (pList1->next != NULL)
	{
		pList1 = pList1->next;
	}
	while (pList2 != NULL)
	{
		pList2 = pList2->next;
	}
	if (pList1 == pList2)
		return 1;
	return -1;
}
//�ཻ���󽻵�
//��һ��
pNode Get_Link_CrossNode(pNode pHead1,pNode pHead2)
{
	pNode pList1 = pHead1;
	pNode pList2 = pHead2;

	int len1 = GetLinkNode(pHead1);
	int len2 = GetLinkNode(pHead2);
	int length = len1 - len2;

	if (length > 0)
	{
		//˵��len1>len2
		while (length--)
		{
			pList1 = pList1->next;
		}
		while (pList1 != pList2)
		{
			pList1 = pList1->next;
			pList2 = pList2->next;
		}
	}
	else
	{
		length = (- length);
		while (length--)
		{
			pList2 = pList2->next;
		}
		while (pList1 != pList2)
		{
			pList1 = pList1->next;
			pList2 = pList2->next;
		}
	}
	return pList1;
}
//�ڶ��֣�
pNode _Get_Link_CrossNode(pNode pHead1, pNode pHead2)
{
	pNode pList1 = pHead1;
	pNode pList2 = pHead2;

	//������һ�������ڵ�λ�ã���L1��β�ڵ�ָ��L2ͷ�����ɻ�
	while (pList1->next != NULL)
	{
		pList1 = pList1->next;
	}
	pList1->next = pList2;
	//��ʱpHead1��Ϊ�����������ڵ�
	return GetCircleEnterNode(pHead1, CheckCircle(pHead1));
}
//13. �ж����������Ƿ��ཻ�����ཻ���󽻵㡣������������ܴ������������桿
//���ж�L1��L2�Ƿ��ཻ
int _Check_Cross(pNode pHead1, pNode pHead2)
{
	pNode Meet1 = CheckCircle(pHead1);//����������
	pNode Meet2 = CheckCircle(pHead2);

	if ((Meet1 == NULL && Meet2 != NULL) || (Meet2 == NULL && Meet1 != NULL))
	{
		return -1;//һ������һ������
	}
	else//����������
	{
		pNode pCur = Meet1;
		do
		{
			pCur = pCur->next;
			if (pCur == Meet2)
			{
				return 1;//�ཻ�������ҵ�һ���ڵ�
			}
		} while (Meet1 != pCur);
	}
	return -1;// ���������������ཻ
}
//�������ཻ��������Ľڵ�(�������ཻ�ڵ�)
//��һ����� һ���ڻ��� һ���ڻ���
//�ڶ������ �������ڻ���
void Get_Link_CrossCircleNode(pNode pHead1, pNode pHead2)
{
	pNode meet1 = GetCircleEnterNode(pHead1, CheckCircle(pHead1));
	pNode meet2 = GetCircleEnterNode(pHead2, CheckCircle(pHead2));

	if (meet1 == meet2)//һ���ڻ���һ���ڻ���
	{
		pNode pCur = _Get_Link_CrossNode(pHead1, pHead2);//�˺�����12������д
		printf("����һ�� %d  ������� %d\n", meet1->_data, pCur->_data);
	}
	else//�����㶼�ڻ���
	{
		pNode p1 = CheckCircle(pHead1);
		pNode p2 = CheckCircle(pHead2);
		printf("����һ�� %d  ������� %d\n", p1->_data, p2->_data);
	}
}


#endif