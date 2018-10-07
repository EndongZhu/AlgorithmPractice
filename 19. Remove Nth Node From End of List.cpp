struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
	ListNode* iter = head ;
	queue<ListNode*> buffer ;
	while(iter != NULL)
	{
		if(buffer.size() <= n)
		{
			ListNode* temp = iter ;
			buffer.push(temp) ;
		}	
		else
		{
			buffer.pop() ;
			ListNode* temp = iter ;
			buffer.push(temp) ;
		}
		iter = iter->next ;	
	}
	ListNode* a = buffer.front() ;
	buffer.pop() ;
	ListNode* b = buffer.front() ;
	buffer.pop() ;
	a->next = b->next ;
	delete(b) ;

	return head ;
}