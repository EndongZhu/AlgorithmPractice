void rotate(vector<vector<int>>& matrix) 
{
	int row = matrix.size() ;
	for(int i = 0 ; i < row/2 ; i++)
	{
		swap(matrix[i],matrix[row-1-i]) ;
	}
	for(int i = 0 ; i < row ; i++)
	{
		int col = matrix[i].size() ;
		for(int j = 0 ; j < col/2 ; j++)
		{
			swap(matrix[i][j],matrix[i][col-1-j]) ;
		}
	}
}