ListNode* rotateRight(ListNode* head, int k) 
{
	if(head == NULL || head->next == NULL)
		return head ;

	int len = 0 ;
	ListNode* iter = head ;
	while(iter)
	{
		len++ ;
		iter = iter->next ;
	}
	k = k%len ;

	for(int i = 0 ; i < k ; i++)
	{
		ListNode* tail = head->next ;
		ListNode* pre = head ;
		while(tail->next)
		{
			pre = tail ;
			tail = tail->next ;
		}

		pre->next = NULL ;
		tail->next = head ;
		head = tail ;
	}     

	return head ;   
}