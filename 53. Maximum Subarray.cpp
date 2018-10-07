int maxSubArray(vector<int>& nums) {
    int len = nums.size() ;
    if(len == 1)
    	return nums[0] ;
    int dp[len] = {0} ;
    dp[0] = nums[0] ;
   	for(int i = 1 ; i < len ; i++)
   	{
   		if(dp[i-1] > 0)
   			dp[i] = dp[i-1] + nums[i] ;
   		else
   			dp[i] = nums[i] ;
   	}
   	int max_ = INT_MIN ;
   	for(int i = 0 ; i < len ; i++)
   	{
   		if(dp[i] > max_)
   			max_ = dp[i] ;
   	}
   	return max_ ;
}
