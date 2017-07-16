//合并两个有序链表

PNode Merge(const PNode* pHead1, const PNode* pHead2)
{
	if(pHead1 ==NULL && pHead2 == NULL)
		return NULL;
	else if(pHead1 == NULL)
		return *pHead2;
	else if(pHead2 == NULL)
		return *pHead1;
	else
	{
		PNode Head1 = *pHead1;
		PNode Head2 = *pHead2;
		PNode pNewHead = NULL;
		PNode pCur = NULL;
		
		if(Head1->data < Head2->data)
		{	
	        pNewHead = Head1;
			Head1 = Head1->next;
		}
		else
		{
			pNewHead = Head2;
			Head2 = Head2->next;
		}
		pCur = pNewHead;
		
		while(Head1 && Head2)
		{
			if(Head1->data < Head2->data)
			{	
	            pCur->next = Head1;
			    Head1 = Head1->next;
			}
			else
			{
				pCur->next = Head2;
				Head2 = Head2->next;
			}
			pCur = pCur->next;
		}
		
	}
	if (NULL == pCur1)  
    {  
        pCur->next = Head2;  
    }  
    else  
    {  
        pCur->next = Head2;  
    }
	return pNewHead;
	
}