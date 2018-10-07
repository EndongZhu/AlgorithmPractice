int longestValidParentheses(string s) 
{
	int len = s.size() ;
	int dp[len+1] = 0 ;
	if(len < 2)
		return 0 ;
	if(s[0] == '(' && s[1] == ')')
		dp[1] = 2 ;
	for(int i = 2 ; i < len ; i++)
	{
		if(s[i]==')' && s[i-1] == '(')
		{
			dp[i] = dp[i-2] + 2 ; 
		}
		else if(s[i] == ')' && s[i-1] == ')')
		{
			int pos = i-1-dp[i-1] ;
			if(pos == 0 && s[pos] == '(')
			{
				dp[i] = dp[i-1] + 2 ;
			}	
			if(pos > 0 && s[pos] == '(')
			{
				dp[i] = dp[pos-1] + dp[i-1] + 2 ;
			}
		}
	}
	int max_ = -1 ;
	for(int i = 0 ; i < len ; i++)
	{
		if(max_ < dp[i])
		{
			max_ = dp[i] ;
		}
	}
	return max_ ;

}