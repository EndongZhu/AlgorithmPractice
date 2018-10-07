bool canJump(vector<int>& nums) 
{
	int len = nums.size() ;
	bool ans = 0 ;
	dfs(nums, 0,len-1,ans) ;
	return ans ;
}

void dfs(vector<int>& nums, int cur, int target, bool& suc)
{
	if(suc)
		return ;
	if(cur == target)
	{
		suc = 1 ;
		return ;
	}
	
	int val = nums[cur] ;
	for(int i = 1 ; i <= val ; i++)
	{
		if(cur+i <= target)
			dfs(nums,cur+i,target,suc) ;
	}
}
