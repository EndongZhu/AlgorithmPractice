struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        if(l != NULL && r != NULL)
            return l->val > r->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
	int k = lists.size() ;
	ListNode* head = new ListNode(0) ; 
	ListNode* iter = head ;

	priority_queue<ListNode *, vector<ListNode *>, compare> q;
    
    for(int i = 0 ; i < k ; i++)
    {
        if(lists[i] != NULL)
            q.push(lists[i]) ;
    }

	if(q.empty())	return NULL ;

	while(!q.empty())
	{
		ListNode* elem = q.top() ;
		q.pop() ;
		if(elem->next != NULL)
		{
			q.push(elem->next) ;
		}
		iter->next = elem ;
        iter = iter->next ;
	}
	head = head->next ;
	return head ;
}