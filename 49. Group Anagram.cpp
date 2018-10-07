vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
	vector<vector<string>> ans ;
	multimap<string,string> s_map ;
	int len = strs.size() ;
	set<string> key_set ;
	for(int i = 0 ; i < len ; i++)
	{
		string tmp = strs[i] ;
		sort(tmp.begin(),tmp.end()) ;
		s_map.insert(pair<string,string>(tmp,strs[i])) ;
		key_set.insert(tmp) ;
	}

	for (set<int>::iterator it=key_set.begin(); it!=key_set.end(); ++it)
	{
		vector<string> ans_tmp ;
		string key_cur = *it ;
		multimap<string,string>:iterator m_it
		for(m_it = s_map.lower_bound(key_cur); it != s_map.upper_bound(key_cur) ; ++it)
		{
			ans_tmp.push_back(it->second) ;
		}
		ans.push_back(ans_tmp) ;
	}
	return ans ;
}