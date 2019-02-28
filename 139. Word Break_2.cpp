class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        queue <string> que;
        que.push(s);
        while(!que.empty()) {
            string cur = que.front();
            que.pop();
            for (int i = 0; i < wordDict.size(); i++) {
                if (wordDict[i] == cur) {
                    return true;
                } else if (cur.substr(0, wordDict[i].size()) == cur) {
                    que.push(cur.substr(wordDict[i].size()));
                }
            }
        }
        return false;
    }
};
