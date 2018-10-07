vector<vector<int>> permute(vector<int>& nums) 
{
	sort(nums.begin(),nums.end()) ;
	vector<vector<int>> ans ;
	vector<int> ini ;
	vector<bool> used(nums.size(),0) ;
	dfs(ans , used, ini , nums) ;
	return ans ;
}

void dfs(vector<vector<int>>& ans , vector<bool>& used, vector<int>& cur, vector<int>& nums)
{
	if(cur.size() == nums.size())
	{
		ans.push_back(cur) ;
		return ;
	}

	for(int i = 0 ; i < nums.size() ; i++)
	{
		if(used[i])	continue ;
		if(i > 0 && nums[i] == nums[i-1] && !used[i-1])	continue ;
		cur.push_back(nums[i]) ;
		used[i] = 1 ;
		dfs(ans,used,cur,nums) ;
		used[i] = 0 ;
		cur.pop_back() ;
	}
}