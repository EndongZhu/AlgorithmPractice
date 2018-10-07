int maxProfit(vector<int>& prices) {
	int size = prices.size() ;
	if(size <= 1)
		return 0 ;
	
	int val[3][size] ;
	memset(val,0,sizeof(int)*size*size) ;
	for(int k = 1; k <= 2; k++)
	{
		int min = prices[0] ;
		for(int i = 1; i < size; i++)
		{
			min = min(min,prices[i]-val[k-1][i-1]);
			val[k][i] = max(val[k][i-1],prices[i]-min);
		}
	}
	return val[2][size-1] ;
}