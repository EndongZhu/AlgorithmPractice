int minimumTotal(vector<vector<int>>& triangle) 
{
	int row = triangle.size() ;
	int pre_res[row] ;
	int res[row] ;
	for(int i = 0; i < row; i++)
	{
		res[i] = INT_MAX ;
	}
	pre_res[0] = triangle[0][0] ;

	for(int i = 0 ; i < row-1; i++)
	{
		int col = triangle[i].size() ;
		for(int j = 0; j < col; j++)
		{
			int num1 = pre_res[i]+triangle[i+1][j] ;
			int num2 = pre_res[i]+triangle[i+1][j+1] ;
			if(num1 < res[j])
				res[j] = num1 ;
			if(num2 < res[j+1])
				res[j+1] = num2 ;
		}
		for(int j = 0; j < col+1; j++)
		{
			pre_res[j] = res[j] ;
			res[j] = INT_MAX ;
		}
	}        
	int ans = INT_MAX ;
	for(int i = 0 ; i < row; i++)
	{
		ans = min(ans,pre_res[i]);
	}
	return ans ;
}