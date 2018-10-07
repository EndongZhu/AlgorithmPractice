int numTrees(int n) 
{
	int dp[101][101] ;
	dp[0][0] = 1 ;
	for(int i = 1 ; i <= n ; i++)
	{
		int sum = 0 ;
		for(int j = 1 ; j <= i ; j++)
		{
			dp[i][j] = dp[j-1][0]*dp[i-j][0] ;
			sum += dp[i][j] ;
		}
		dp[i][0] = sum ;
	}        

	return dp[n][0] ;
}