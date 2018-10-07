ListNode* partition(ListNode* head, int x) 
{
	ListNode* left = new ListNode(0);
	ListNode* left_iter = left ;
	ListNode* right = new ListNode(0);
	ListNode* right_iter = right ;

	ListNode* iter = head ;
	while(iter)
	{
		if(iter->val < x)
		{
			left_iter->next = iter ;
			left_iter = left_iter->next ;
		}
		else
		{
			right_iter->next = iter ;
			right_iter = right_iter->next ;
		}
		iter = iter->next ;
	}
	left_iter->next = right->next ;
	right_iter->next = NULL ;

	return left->next ;
}