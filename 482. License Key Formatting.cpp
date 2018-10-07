string licenseKeyFormatting(string S, int K) {
    string ans = "" ;
    int len = S.size() ;
    int ch_cnt = 0 ;
    for(int i = len-1; i >= 0; i--) {
        if(S[i] == '-')
            continue ;
        else if(S[i] >= 'a' && S[i] <= 'z')
            S[i] = S[i] + ('A'-'a') ;
        ++ch_cnt ;
        ans.insert(ans.begin(),S[i]) ;
        if(ch_cnt == K) {
            ch_cnt = 0 ;
            ans.insert(ans.begin(),'-') ;
        }
    }
    if(ans[0] == '-')
        ans.erase(ans.begin()) ;
    return ans ;
}
