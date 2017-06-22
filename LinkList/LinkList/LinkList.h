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

/***************面试题接口**********************/
//1.比较顺序表和链表的优缺点，说说它们分别在什么场景下使用？
//2. 从尾到头打印单链表
//3. 删除一个无头单链表的非尾节点（不能遍历链表）
//4. 在无头单链表的一个非头节点前插入一个节点
//5. 单链表实现约瑟夫环(JosephCircle)
//6. 逆置 / 反转单链表
//7. 单链表排序（冒泡排序&快速排序）
//8. 合并两个有序链表, 合并后依然有序
//9. 查找单链表的中间节点，要求只能遍历一次链表
//10. 查找单链表的倒数第k个节点，要求只能遍历一次链表
//11. 判断单链表是否带环？若带环，求环的长度？求环的入口点？并计算每个算法的时间复
//杂度&空间复杂度。
//12. 判断两个链表是否相交，若相交，求交点。（假设链表不带环）
//13. 判断两个链表是否相交，若相交，求交点。（假设链表可能带环）【升级版】
//14. 复杂链表的复制。一个链表的每个节点，有一个指向next指针指向下一个节点，还有一
//个random指针指向这个链表中的一个随机节点或者NULL，现在要求实现复制这个链表，
//返回复制后的新链表。
//15. 求两个已排序单链表中相同的数据。void UnionSet(Node* l1, Node* l2);

//2.从尾到头打印单链表
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

//3. 删除一个无头单链表的非尾节点（不能遍历链表）
void EraseNotTail(pNode pos)
{
	pNode del = pos->next;
	pos->_data = del->_data;
	pos->next = del->next;
	free(del);

}

//4. 在无头单链表的一个非头节点前插入一个节点
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
//5.单链表的约瑟夫环，循环删除第K个节点
//约瑟夫环（约瑟夫问题）是?个数学的应?问题：
// 已知n个?（以编号1， 2， 3...n分别表?）围坐在?张//圆桌周围。
// 从编号为k的?开始报数，数到m的那个?出列；他的下?个?又从1开始报数，数到m的那个?
// 又出列；依此规律重复下去，直到圆桌周围的?全部出列。
pNode JosephCycle(pNode* pHead, int num)//函数执行的前提条件是链表先构成环
{
	assert(pHead);
	pNode pCur = *pHead;
	int _num = num;
	while (pCur)
	{
		//当只有一个节点时，退出
		if (pCur == pCur->next)
			break;

		while (--_num)
		{
			pCur = pCur->next;
		}
		pNode del = pCur->next;
		printf("删除 ：%d \n", pCur->_data);
		pCur->_data = del->_data;
		pCur->next = del->next;
		free(del);
		_num = num;
	}
	*pHead = pCur;
	return pCur;
}

//6.逆置单链表
//以头插方式建立新连接，从而逆置
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

//7.单链表排序（冒泡排序，快排）
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

//8.合并两个有序单链表
pNode Merge(pNode* pHead1, pNode* pHead2)
{
	assert(pHead1&&pHead2);//1.两者均为空

	//2.其中一个为空
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
	//假设为升序合并，判定两个头哪一个作为新链表的头
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

//9. 查找单链表的中间节点，要求只能遍历一次链表
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

//10. 查找单链表的倒数第k个节点，要求只能遍历一次链表
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