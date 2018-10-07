struct grid
{
	int a ;
	int b ;
	int cnt ;
	grid(Solution::grid& ano) : a(ano.a), b(ano.b), cnt(ano.cnt) {}
	grid(int c, int d,int e) : a(c), b(d), cnt(e) {}
};

bool exist(vector<vector<char>>& board, string word) 
{
	int len = word.size() ;
	if(len == 0)
		return false ;
	int m = board.size() ;
	if(m == 0)
		return false ;
	int n = board[0].size() ;

	bool visited[m][n] = {0} ;
	for(int i = 0 ; i < m ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			if(board[i][j] == word[0])
			{
				grid tmp(i,j,1) ;
				visited[i][j] = 1 ;
				if(dfs(board,word,tmp,visited))
					return true ;
				visited[i][j] = 0 ;
			}
		}
	}

	return false ;
}

bool dfs(vector<vector<char>>& board, string word, grid& elem, bool visited[][])
{
	if(elem.size() == word.size())
		return true ;

	int i = elem.a ;
	int j = elem.b ;
	if(i-1 >= 0 && board[i-1][j] == word[elem.cnt])
	{
		grid tmp(elem) ;
		tmp.a -= 1 ;
		tmp.cnt += 1 ;
		visited[tmp.a][tmp.b] = 1 ;
		if(dfs(board,word,tmp,visited))
			return true ; 
		visited[tmp.a][tmp.b] = 0 ;
	}
	if(i+1 < m && board[i+1][j] == word[elem.cnt])
	{
		grid tmp(elem) ;
		tmp.a += 1 ;
		tmp.cnt += 1 ;
		visited[tmp.a][tmp.b] = 1 ;
		if(dfs(board,word,tmp,visited))
			return true ; 
		visited[tmp.a][tmp.b] = 0 ;
	}
	if(j-1 >= 0 && board[i][j-1] == word[elem.cnt])
	{
		grid tmp(elem) ;
		tmp.b -= 1 ;
		tmp.cnt += 1 ;
		visited[tmp.a][tmp.b] = 1 ;
		if(dfs(board,word,tmp,visited))
			return true ; 
		visited[tmp.a][tmp.b] = 0 ;
	}
	if(j+1 < n && board[i][j+1] == word[elem.cnt])
	{
		grid tmp(elem) ;
		tmp.b += 1 ;
		tmp.cnt += 1 ;
		visited[tmp.a][tmp.b] = 1 ;
		if(dfs(board,word,tmp,visited))
			return true ; 
		visited[tmp.a][tmp.b] = 0 ;
	}

	return false ;
}