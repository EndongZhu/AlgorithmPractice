vector<int> inorderTraversal(TreeNode* root) 
{
	vector<int> res ;
	Traversal(root,res) ;
	return res ;
}

void Traversal(TreeNode* cur, vector<int> &ans)
{
	if(cur != NULL)
	{
		Traversal(cur->left, ans) ;
		ans.push_back(cur->val) ;
		Traversal(cur->right,ans) ;
	}
}