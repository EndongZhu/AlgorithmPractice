vector<vector<int>> combine(int n, int k) 
{
	vector<int> ini ;
	vector<vector<int>> ans ;
	dfs(ans,ini,0,n,k) ;
	return ans ;
}

void dfs(vector<vector<int>> &ans, vector<int> &cur, int start, int n, int k)
{
	if(cur.size() == k)
	{
		ans.push_back(cur) ;
		return ;
	}


	for(int i = start+1; i <= n ; i++)
	{
		cur.push_back(i) ;
		dfs(ans,cur,i,n,k) ;
		cur.pop_back() ;
	}
}
