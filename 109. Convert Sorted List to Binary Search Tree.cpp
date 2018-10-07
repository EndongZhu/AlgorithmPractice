TreeNode* sortedListToBST(ListNode* head) 
{
	if(head == NULL)
		return NULL ;
	ListNode* iter = head ;
	ListNode* cur_mid = head ;
	int cur_mid_pos = 0 ;
	int cur_len = 0 ;
	ListNode* left_tree = new ListNode(0) ;
	ListNode* left_tree_iter = left_tree ;
	while(iter != NULL)
	{
		if(cur_mid_pos < (cur_len+1)/2)
		{
			left_tree_iter->next = new ListNode(cur_mid->val) ;
			left_tree_iter = left_tree_iter->next ;
			cur_mid = cur_mid->next ;
			++cur_mid_pos ;
		}
		iter = iter->next ;
		++cur_len ;
	}
	left_tree = left_tree->next ;
	ListNode* right_tree = cur_mid->next ;

	TreeNode* cur = new TreeNode(cur_mid->val) ;
	cur->left = sortedListToBST(left_tree) ;
	cur->right = sortedListToBST(right_tree) ;

	return cur ;
}