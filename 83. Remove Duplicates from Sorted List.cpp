ListNode* deleteDuplicates(ListNode* head) 
{
	if(head == NULL || head->next == NULL)
		return head ;
	ListNode* cur = head->next ;
	ListNode* pre = head ;
	while(cur)
	{
		if(cur->val == pre->val)
		{
			pre->next = cur->next ;
			cur = cur->next ;
		}
		else
		{
			pre = cur ;
			cur = cur->next ;
		}
	}
	return head ;
}