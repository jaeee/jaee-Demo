PNode Reverse(PNode* pHead)
{
	//头插
	assert(pHead);
	PNode pCur = *pHead;
	PNode pPre = pCur;
	PNode pNewHead = NULL;
	while(pCur)
	{
		pCur = pCur->next;
		pPre->next = pNewHead;
		pNewHead = pPre;
		pPre = pCur;
	}
	return pNewHead;
}


int GetLinkListNode(PNode* pHead)
{
	PNode pCur = *pHead;
	if(pHead == NULL)
		return 0;
	return 1+GetLinkListNode(pCur->next);
}
PNode Find_k_Node(PNode* pHead, int k)
{
	PNode pFast = *pHead;
	PNode pSlow = *pHead;
	
	if(GetLinkListNode(pHead) < k)
		return -1;
	while(k--)
	{
		pFast = pFast->next;
	}
	while(pFast != NULL)
	{
		pFast = pFast->next;
		pSlow = pSlow->next;
	}
	return pSlow;
}