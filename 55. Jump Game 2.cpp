bool canJump(vector<int>& nums) 
{
	int len = nums.size() ;
	bool stat[len] = {0} ;
	int left_most = len-1 ;
	stat[len-1] = 1 ;
	for(int i = len-2 ; i >= 0 ; i--)
	{
		if(i+nums[i] >= left_most)
		{
			stat[i] = 1 ;
			left_most = i ;
		}
	}
	return stat[0] ;
} 
