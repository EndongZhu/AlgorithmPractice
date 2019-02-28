class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int shortest = INT_MAX;
        vector<vector<string>> ans;
        unordered_set<string> init;
        init.insert(beginWord);
        queue<pair<string, unordered_set<string>>> que;
        que.push(make_pair(beginWord, init));
        while (!que.empty()) {
            pair<string, unordered_set<string>> cur = que.front();
            que.pop();
            if (cur.second.size() > shortest)
                break;
            if (cur.first == endWord) {
                shortest = cur.second.size();
                vector<string> v;
                for (auto elem : cur.second) {
                    v.push_back
                }
                ans.push_back(.second);
            }
            for (int i = 0; i < wordList.size(); i++) {
                string word = wordList[i];
                if (cur.second.find(word) != cur.second.end())
                    continue;
                if (valid(cur.first, word)) {
                    unordered_set<string> v(cur.second);
                    v.insert(word);
                    que.push(make_pair(word, v));
                }
            }
        }

        return ans;
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
};
