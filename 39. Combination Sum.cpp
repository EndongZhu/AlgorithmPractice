vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
{
	int len = candidates.size() ;
	queue<vector<int>> que ;
	vector<vector<int>> ans ;
	for(int i = 0 ; i < len ; i++)
	{
		int temp = candidates[i] ;
		if(temp <= target)
		{
			vector<int> elem ;
			elem.push_back(temp) ;
			que.push(elem) ;
		}
	}
	while(!que.empty())
	{
		vector<int> elem = que.front() ;
		que.pop() ;
		int elem_len = elem.size() ;
		int sum_ = 0 ;
		for(int j = 0 ; j < elem_len ; j++)
		{
			sum += elem[j] ;
		}
		if(sum_ == target)
		{
			ans.push_back(elem) ;
			continue ;
		} 
		int comp = target - sum_ ;
		int last_num = elem[elem_len-1] ;
		for(int j = 0 ; j < len ; j++)
		{
			if(candidates[j] <= comp && candidates[j] >= last_num)
			{
				vector<int> elem_new = elem ;
				elem_new.push_back(candidates[j]) ;
				que.push(elem_new) ;
			}
		}
	}	
	return ans ;
}