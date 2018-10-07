/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
{
    vector<vector<int>> ans ;
	if(root == NULL)
		return ans ;

	queue<TreeNode*> node_que ;
	queue<int> depth ;

	node_que.push(root) ;
	depth.push(1) ;

	while(!node_que.empty())
	{
		TreeNode* cur = node_que.front() ;
		node_que.pop() ;
		int cur_dep = depth.front() ;
		depth.pop() ;

		if(cur_dep > ans.size())
		{
			vector<int> new_v ;
			new_v.push_back(cur->val) ;
			ans.push_back(new_v) ;
		}
		else
		{
			if(cur_dep%2 == 1)
				ans[cur_dep-1].push_back(cur->val) ;
			else
				ans[cur_dep-1].insert(ans[cur_dep-1].begin(),cur->val) ;
		}

		if(cur->left != NULL)
		{
			node_que.push(cur->left) ;
			depth.push(cur_dep+1) ;
		}
		if(cur->right != NULL)
		{
			node_que.push(cur->right) ;
			depth.push(cur_dep+1) ;
		}
	}
    
    return ans ;
}
};