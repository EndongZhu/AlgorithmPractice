class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        if (len == 0) {
            return false;
        }
        bool dp[len];
        dp[0] = true;
        for (int i = 1; i <= len; i++) {
            bool suc = false;
            for (int j = 0; j < i; j++) {
                bool contains = dict.find(s.substr(j+1,i)) != dict.end();
                if (dp[j] && contains) {
                    suc = true;
                }
            }
            dp[i] = suc;
        }
        return dp[len];
    }
};
