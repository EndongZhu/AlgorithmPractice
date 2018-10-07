vector<vector<int>> permute(vector<int>& nums) 
{
	sort(nums.begin(),nums.end()) ;
	vector<vector<int>> ans ;
	vector<int> ini;
	dfs(ans , ini , nums) ;
	return ans ;
}

void dfs(vector<vector<int>>& ans , vector<int>& cur, vector<int>& nums)
{
	if(cur.size() == nums.size())
	{
		ans.push_back(cur) ;
		return ;
	}

	for(int i = 0 ; i < nums.size() ; i++)
	{
		if(nums[i] != INT_MIN)
		{
			int elem = nums[i] ;
			cur.push_back(elem) ;
			nums[i] = INT_MIN ;
			dfs(ans,cur,nums) ;
			nums[i] = elem ;
			cur.pop_back() ;
		}
	}
}