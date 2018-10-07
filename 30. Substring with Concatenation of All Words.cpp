vector<int> findSubstring(string s, vector<string>& words) 
{
	vector<int> ans ;
	int wd_num = words.size() ;
	if(wd_num == 0)
		return ans ;

	int wd_len = words[0].size() ;
	int s_len = s.size() ;
	if(wd_len*wd_num > s_len)
		return ans ;

	map<string,int> mapp ;
	for(int i = 0 ; i < wd_num ; i++)
	{
		string temp = words[i] ;
		if(mapp.find(temp) == mapp.end())
			mapp[temp] = 1 ;
		else
			mapp[temp] += 1 ;
	}

	for(int i = 0 ; i <= s_len-wd_len*wd_num ; i++)
	{
		map<string,int> mapp_c(mapp) ;
		for (int j = i; j < i+s_len*wd_num; j+=wd_len)
		{
			string temp = s.substr(j,wd_len) ;
			if(mapp_c.find(temp) == mapp_c.end())
				break ;
			else
			{
				int cnt = mapp_c[temp] ;
				--cnt ;
				if(cnt == 0)
				{
					mapp_c.erase(temp) ;
				}
				else
					mapp_c[temp] = cnt ;
			}
		}
		if(mapp_c.empty())
			ans.push_back(i) ;
	}
	return ans ;
}