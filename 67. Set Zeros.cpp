void setZeroes(vector<vector<int>>& matrix) 
{
    int m = matrix.size() ;
    if(m == 0) return ;
    int n = matrix[0].size() ;
    
    bool prod_row[m] = {0} ;
    bool prod_col[n] = {0} ;

    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
        	if(matrix[i][j] == 0)
        	{
        		prod_row[i] = 1 ;
        		prod_col[j] = 1 ;
        	}
        }
    }

    for(int i = 0 ; i < m ; i++)
    {
    	for(int j = 0 ; j < n ; j++)
    	{
    		if(prod_row[i] == 1 || prod_col[j] == 1)
    			matrix[i][j] = 0 ;
    	}
    }
}