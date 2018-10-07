vector<vector<int>> subsetsWithDup(vector<int>& nums) 
{
    sort(nums.begin(),nums.end()) ;
	vector<vector<int>> ans ;
	int len = nums.size() ;
	for(int i = 0 ; i <= len ; i++)
	{
		vector<int> ini ;
		dfs(ans,ini,0,nums,i) ;
	}
	return ans ;
}

void dfs(vector<vector<int>> &ans, vector<int> &cur, int start, vector<int>& nums, int k)
{
	if(cur.size() == k)
	{
		ans.push_back(cur) ;
		return ;
	}

	int n = nums.size() ;
	for(int i = start; i < n ; i++)
	{
        if(i != start && nums[i] == nums[i-1])
            continue ;
		cur.push_back(nums[i]) ;
		dfs(ans,cur,i+1,nums,k) ;
		cur.pop_back() ;
	}
}