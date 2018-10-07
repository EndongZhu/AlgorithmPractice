vector<int> grayCode(int n) 
{
	int dp[10001] = {0} ;
	int len = pow(2,n) ;
	int pos = 0 ;
	for(int i = 1 ; i <= n ; i++)
	{
		int tmp_len = pow(2,i-1) ;
		int tmp_pos = pos-1 ;
		for(int j = 0 ; j < tmp_len ; j++)
		{
			dp[pos++] = dp[tmp_pos--]+tmp_len ;
		}
	}      
	vector<int> ans ;
	for(int i = 0 ; i < len ; i++)
	{
		ans.push_back(dp[i]) ;
	}
	return ans ;
}