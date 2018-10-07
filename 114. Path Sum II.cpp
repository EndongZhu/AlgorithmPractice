vector<vector<int>> pathSum(TreeNode* root, int sum) 
{
	vector<vector<int>> res ;
	vector<int> ini ;
	searchPath(root,ini,res,sum) ;
	return res ;
}

void searchPath(TreeNode* nd, vector<int> &cur, vector<vector<int>> &ans, int sum)
{
	if(nd == NULL)
		return ;
	else if(nd->val == sum && nd->left == NULL && nd->right == NULL)
	{
		cur.push_back(nd->val) ;
		ans.push_back(cur) ;
		cur.pop_back() ;
		return ;
	}
	else
	{
		cur.push_back(nd->val) ;
		searchPath(root->left, cur, ans, sum-(nd->val)) ;
		searchPath(root->right, cur, ans, sum-(nd->val)) ;
		cur.pop_back() ;
		return ;
	}
}