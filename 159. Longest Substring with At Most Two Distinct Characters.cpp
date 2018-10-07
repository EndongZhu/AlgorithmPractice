int lengthOfLongestSubstringTwoDistinct(string s) {
        int len = s.size() ;
        if(len == 0)
            return 0 ;
        int dp[len][2] = {0};
        char mem[len] = {0};
        dp[0][0] = 1 ;
        dp[0][1] = 0 ;
        for(int i = 1; i < len; i++) {
            dp[i][0] = s[i] == s[i-1] ? dp[i-1][0]+1 : 1 ;
            if(s[i] == s[i-1] || s[i] == mem[i-1]) {
                mem[i] = s[i] == s[i-1] ? mem[i-1] : s[i-1] ;
                dp[i][1] = dp[i-1][1] == 0 ? 0 : dp[i-1][1]+1 ;
            }
            else {
                mem[i] = s[i-1] ;
                dp[i][1] = dp[i-1][0] + 1 ;
            }
        }
        int ans = 0 ;
        for(int i = 0 ; i < len; i++) {
            ans = max(ans,max(dp[i][0],dp[i][1])) ;
        }
        return ans ;
    }
