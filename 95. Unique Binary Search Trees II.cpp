vector<TreeNode*> generateTrees(int n) 
{
	vector<TreeNode*> res ;
	if(n == 0) 
		return res ;
	res = BuildTree(1,n) ;
	return res ;
}

vector<TreeNode*> BuildTree(int start, int end)
{
	vector<TreeNode*> ans ;
	if(start > end)
	{
		ans.push_back(NULL) ;
		return ans ;
	}
	if(start == end)
	{
		TreeNode* nd = new TreeNode(start) ;
		ans.push_back(nd) ;
		return ans ;
	}
	else
	{
		for(int i = start ; i <= end ; i++)
		{
			vector<TreeNode*> left_tree ;
			left_tree = BuildTree(start,i-1) ;
			vector<TreeNode*> right_tree ;
			right_tree = BuildTree(i+1,end) ;
			for(int i = 0 ; i < left_tree.size() ; i++)
			{
				for(int j = 0 ; j < right_tree.size() ; j++)
				{
					TreeNode* root = new TreeNode(i) ;
					root->left = left_tree[i] ;
					root->right = right_tree[j] ;
					ans.push_back(root) ;
				}
			}
		}
		return ans ;
	}
}