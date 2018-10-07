void connect(TreeLinkNode *root) 
{
	if(root == NULL)
		return ;
	if(root->left!=NULL && root->right!=NULL)
	{
		root->left->next = root->right ;
		TreeLinkNode* iter = root->next ;
		while(iter != NULL)
		{
			if(iter->left != NULL)
			{
				root->right->next = iter->left ;
				break ;
			}
			else if(iter->right != NULL)
			{
				root->right->next = iter->right ;
				break ;
			}
			iter = iter->next ;
		}
		connect(root->right) ;
		connect(root->left) ;
	}        
	else if(root->left != NULL)
	{
		TreeLinkNode* iter = root->next ;
		while(iter != NULL)
		{
			if(iter->left != NULL)
			{
				root->left->next = iter->left ;
				break ;
			}
			else if(iter->right != NULL)
			{
				root->left->next = iter->right ;
				break ;
			}
			iter = iter->next ;
		}
		connect(root->left) ;
	}
	else if(root->right != NULL)
	{
		TreeLinkNode* iter = root->next ;
		while(iter != NULL)
		{
			if(iter->left != NULL)
			{
				root->right->next = iter->left ;
				break ;
			}
			else if(iter->right != NULL)
			{
				root->right->next = iter->right ;
				break ;
			}
			iter = iter->next ;
		}
		connect(root->right) ;
	}
	
	return ;
}