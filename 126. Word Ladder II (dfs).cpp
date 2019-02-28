class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        shortest = INT_MAX;
        vector<vector<string>> ans;
        vector<string> v;
        dfs(beginWord, endWord, v, wordList, ans);
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i].size() > shortest) {
                ans.erase(ans.begin()+i);
                i--;
            }
        }
        return ans;
    }

    void dfs(string cur, string tar, vector<string> seq, vector<string>& wordList, vector<vector<string>> &ans) {
        seq.push_back(cur);
        if (cur == tar) {
            ans.push_back(seq);
            if (seq.size() < shortest)
                shortest = seq.size();
        }
        for (int i = 0; i < wordList.size(); i++) {
            string word = wordList[i];
            if (valid(cur, word)) {
                wordList.erase(wordList.begin()+i);
                dfs(word, tar, seq, wordList, ans);
                wordList.insert(wordList.begin()+i, word);
            }
        }
    }

    bool valid(string& a, string& b) {
        if (a.size() != b.size())
            return false;
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                ++cnt;
        }
        return cnt == 1;
    }
private:
    int shortest;
};
