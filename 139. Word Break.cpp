bool wordBreak(string s, vector<string>& wordDict) {
    int dict_size = wordDict.size() ;
    int len = s.size() ;
    if(len == 0)
        return true ;
    if(dict_size == 0)
        return false ;
    bool dp[len+1] = {0} ;
    dp[0] = 1 ;
    for(int i = 1; i <= len; i++)
    {
        for(int j = 0; j < dict_size; j++)
        {
            int item_len = wordDict[j].size() ;
            if(i-item_len >= 0 && dp[i-item_len])
            {
                string s_sub = s.substr(i-item_len, item_len) ;
                if(s_sub == wordDict[j])
                    dp[i] = 1;
            }
        }
    }
    return dp[len] ;
}
