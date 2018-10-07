vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
{
	vector<vector<int>> ans ;
	vector<int> init ;
	sort(candidates.begin(),candidates.end()) ;
	combinationSumSearch(ans, init, candidates, target) ;
	return ans ;
}

void combinationSumSearch(vector<vector<int>> &ans, vector<int> cur, vector<int> candidates, int target)
{
	if(target == 0)
	{
		ans.push_back(cur) ;
		return ;
	}
	int cur_len = cur.size() ;
	int candidate_len = candidates.size() ;
	int last_num = -1 ;
	if(cur_len > 0)
		last_num = cur[cur_len-1] ;
	for(int i = 0 ; i < candidate_len ; i++)
	{
		if(candidates[i] <= target && candidates[i] >= last_num)
		{
			int num = candidates[i] ;
			cur.push_back(num) ;
			vector<int> new_candidates = candidates ;
			new_candidates.erase(new_candidates.begin()+i) ;
			combinationSumSearch(ans, cur, new_candidates, target-num) ;
			cur.pop_back() ;
		}
	}
}