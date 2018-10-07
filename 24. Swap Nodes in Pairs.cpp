ListNode* swapPairs(ListNode* head) 
{
	ListNode* ans = new ListNode(0) ;
	ListNode* iter = head ;
	ListNode* last_end = ans ;
	while(1)
	{
		if(iter == NULL)
		{
			last_end->next = NULL ;
			break ;
		}
		else if(iter->next == NULL)
		{
			last_end->next = iter ;
			break ;
		}
		else
		{
			ListNode* first = iter ;
			ListNode* second = iter->next ;
			ListNode* temp = second->next ;
			last_end->next = second ;
			second->next = first ;
			last_end = first ;
			iter = temp ;
		}		
	}
	ans = ans->next ;
	return ans ;
}