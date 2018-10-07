bool hasPathSum(TreeNode* root, int sum) 
{
	if(root == NULL)
		return false ;
	int cur = root->val ;
	else if(cur == sum)
		return true ;
	else if(cur > sum)
		return false ;
	else
		return hasPathSum(root->left, sum-cur) || hasPathSum(root->right, sum-cur) ;
}