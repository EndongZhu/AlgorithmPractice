vector<vector<int>> levelOrder(TreeNode* root) 
{
	vector<vector<int>> ans ;

	if(root==NULL)
		return ans ;

	queue<int> depth ;
	queue<TreeNode*> que ;

	depth.push(1) ;
	que.push(root) ;

	while(!depth.empty() && !que.empty()) 
	{
		TreeNode* cur = que.front() ;
		int cur_dep = depth.front() ;
		que.pop() ; 
		depth.pop() ;

		if(cur_dep > ans.size())
		{
			vector<int> new_v ;
			new_v.push_back(cur->val) ;
			ans.push_back(new_v) ;
		}
		else
			ans[cur_dep-1].push_back(cur->val) ;

		if(cur->left)
		{
			que.push(cur->left) ;
			depth.push(cur_dep+1) ;
		}
		if(cur->right)
		{
			que.push(cur->right) ;
			depth.push(cur_dep+1) ;
		}
	}

	return ans ;
}