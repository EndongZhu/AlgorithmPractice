void connect(TreeLinkNode *root) 
{
	if(root == NULL)
		return ;
	if(root->left!=NULL && root->right != NULL)
	{
		root->left->next = root->right ;
		if(root->next != NULL)
		{
			root->right->next = root->next->left ;
		}
		connect(root->left) ;
		connect(root->right) ;
	}        
	
	return ;
}