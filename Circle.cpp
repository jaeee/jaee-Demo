
PNode LinkList_Check_Circle(PNode* pHead)
{
	assert(pHead);
	
	PNode Head = *pHead;
	if(Head->next == NULL)
	{
		return NULL;
	}
	PNode pFast = Head;
	PNode pSlow = Head;
}