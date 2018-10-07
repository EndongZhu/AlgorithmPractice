bool isSymmetric(TreeNode* root) 
{
	if(!root || !root->left || !root->right)
		return false ;
	TreeNode* left_iter = root->left ;
	TreeNode* right_iter = root->right ;
	
	return compLeftRight(left,right) ;
}

bool compLeftRight(TreeNode* left_iter, TreeNode* right_iter)
{
	if(!left_iter || !right_iter)
		return left_iter==right_iter ;
	else
		return compLeftRight(left_iter->left,right_iter->right) && left_iter->val == right_iter->val && compLeftRight(left_iter->right,right_iter->left) ;
}