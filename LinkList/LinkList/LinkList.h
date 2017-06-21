//void  InitList(PNode* pHead);//初始化
//void  PrintList(PNode pHead);//打印
//int  GetLinkNode(PNode pHead);//获取节点数
//void DestoryNode(PNode* pHead);//销毁链表
//void  PushBack(PNode* pHead, DataType data);//尾插
//void  PopBack(PNode* pHead);//尾删
//void  PushFront(PNode* pHead, DataType data);//头插
//void  PopFront(PNode* pHead);//头删
//PNode Find(PNode pHead, DataType data);//查找data的位置
//void  Erase(PNode* pHead, PNode pos);//删除pos处的节点
//void  EraseNoTaiNode(PNode  pos);//无头指针删除,可采用拷贝下一个结点数据，删除下一个结点
//void  Insert(PNode pos, DataType data);//在pos后面插入一个节点
//void  Remove(PNode* pHead, DataType data);//删除链表中的第一个data
//void  RemoveAll(PNode* pHead, DataType data);//删除链表中所有的data
//void  Test();//测试
//PNode  BuyNode(DataType data);//开辟PNode空间存储data


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

//为新节点开辟空间
pNode BuyNode(DataType data)
{
	pNode tmp = (pNode)malloc(sizeof(Node));
	tmp->_data = data;
	tmp->nedatat = NULL;
	return tmp;
}



//链表初始化
void InitLinkList(pNode* pHead)
{
	*pHead = NULL;
}
//打印单链表
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
//尾插
void PushBack(pNode* pHead, DataType data)
{
	assert(NULL != pHead);
	pNode pCur = *pHead;
	//判断节点是否为空
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
//尾删
void PopBack(pNode* pHead)
{
	assert(NULL != pHead);
	
	pNode pCur = *pHead;

	if (pCur == NULL)
	{
		printf("链表是空的\n");
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
//头插
void PushFront(pNode* pHead, DataType data)
{
	assert(NULL != pHead);
	pNode pCur;
	pCur = BuyNode(data);
	pCur->nedatat = *pHead;
	*pHead = pCur;
}
//头删
void PopFront(pNode* pHead, DataType data)
{
	assert(NULL != pHead);
	pNode pCur = *pHead;
	if (NULL == pCur)
	{
		printf("链表是空的\n");
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
			printf("找到了。。。\n");
			return pCur;
		}
		else
		{
			pCur = pCur->nedatat;
		}
	}
	printf("没有这个数\n");
	return NULL;
}
//删除指定位置节点（是否为头结点！！！）
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
			printf("没有找到\n");
		}
	}
}
//无头指针删除,可采用拷贝下一个结点数据，删除下一个结点
void EraseNoTail(pNode* pHead, pNode pos)
{
	pNode del = pos->nedatat;
	pos->_data = del->_data;
	pos->nedatat = del->nedatat;
	free(del);
	
}
//删除链表中第一个出现的data
void Remove(pNode* pHead, DataType data)
{
	assert(NULL != pHead);
	pNode pCur = *pHead;

	//如果是头结点
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
	printf("没有这个数\n");
}

//删除链表中所有data值
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
		//注意pCur的判空位置
		//while(pCur->_data != data && pCur)
		//若为最后一个节点 按照上面的判断方式第一个条件此时pCur为NULL执行语句会引发异常
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