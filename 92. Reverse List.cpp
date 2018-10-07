ListNode* reverseBetween(ListNode* head, int m, int n) 
{
	ListNode* iter = head ;
	if(iter->next == NULL)
		return head ;
	ListNode* pre = new ListNode(-1) ;
	pre->next = iter ;
	iter = iter->next ;
	int cnt = 1 ;
	ListNode* start = new ListNode(-1) ;
	ListNode* end = new ListNode(-1) ;
	while(iter)
	{
		++cnt ;
		ListNode* next_node = iter->next ;
		if(cnt == m)
		{
			start = pre ;
		}
		if(cnt > m && cnt < n)
		{
			iter->next = pre ;
		}
		if(cnt == n)
		{
			end = iter->next ;
			start->next->next = end ;
			iter->next = pre ;
			start->next = iter ;
		}
		pre = iter ;
		iter = next_node ;
	}

	return head ;
}