int maxProfit(vector<int>& prices) 
{
	int size = prices.size() ;
	int val[size] = {0} ;
	for(int i = 1; i < size; i++)
	{
		val[i] = max(val[i],val[i-1]+(prices[i]-prices[i-1])) ;
	}
	int ans = 0 ;
	for(int i = 0 ; i < size ; i++)
	{
		ans = max(ans,val[i]) ;
	}

	return ans ;
}