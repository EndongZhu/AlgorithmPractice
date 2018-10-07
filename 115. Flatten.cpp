void flatten(TreeNode* root) 
{
	if(root == NULL || (root->left == NULL && root->right == NULL))
		return ;
	flatten(root->left) ;
	flatten(root->right) ;
	TreeNode* iter = root->left ;
	if(iter == NULL)
		return ;
    while(iter->right != NULL)
    {
        iter = iter->right ;
    }
    iter->right = root->right ;
    root->right = root->left ;
    root->left = NULL ;
}