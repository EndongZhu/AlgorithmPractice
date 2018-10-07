bool eval(string s1, string s2)
{
	if(s1.size()!=s2.size())
		return false ;
	int cnt = 0 ;
	for(int i = 0 ; i < s1.size(); i++)
	{
		if(s1[i] != s2[i])
			++cnt ; 
	}
	if(cnt == 1)
		return true ;
	else
		return false ;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
{
	pair<string,int> init_node(beginWord,0) ;
	queue<pair<string,int>> que ;
	que.push(init_node) ;
	while(!que.empty())
	{
		pair<string,int> cur = que.front();
		string cur_str = cur.first ;
		int cur_cnt = cur.second ;
		if(cur_str == endWord)
			return cur_cnt ;
		for(int i = 0; i < wordList.size(); i++)
		{
			if(eval(cur_str,wordList[i]))
			{
				pair<string,int> new_node(wordList[i],cur_cnt+1) ;
				que.push(new_node) ;
				wordList[i] = "" ;
			}
		}
	}
	return 0 ;
}