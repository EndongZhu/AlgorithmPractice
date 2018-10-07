ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
	ListNode* head ; 
	ListNode* iter = head ;
	while(l1 != NULL && l2 != NULL)
	{
		if (l1->val < l2->val)
		{
			iter->next = l1 ;
			l1 = l1->next ;
			iter = iter->next ;
		}
		else
		{
			iter->next = l2 ;
			l2 = l2->next ;
			iter = iter->next ;
		}
	}       
	if(l1 != NULL)
		iter->next = l1 ;
	else
		iter->next = l2 ;
	head = head->next ;
	return head ;
}