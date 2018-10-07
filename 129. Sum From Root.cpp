int sumNumbers(TreeNode* root) 
{
	int ans = 0 ;
	if(root == NULL)
		return ans ;
	dfs(root, 0, &ans) ;
	return ans ;
}

void dfs(TreeNode* node, int num, int* sum)
{
	if(node == NULL)
		return ;
	num = num*10 + node->val ;
	if(node->left == NULL && node->right == NULL)
	{
		*sum += num ;
		return ;
	}
	dfs(node->left, num, sum) ;
	dfs(node->right, num, sum) ;

	return ;
}