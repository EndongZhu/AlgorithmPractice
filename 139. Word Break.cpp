class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return helper(s, dict);
    }

    bool helper(string s, unordered_set<string>& wordDict) {
        if (mem.find(s) != mem.end()) {
            return mem[s];
        }
        if (wordDict.find(s) != wordDict.end()) {
            mem[s] = true;
            return true;
        }
        for (int i = 0; i < s.size(); i++) {
            string new_s = s.substr(0, i+1);
            if (wordDict.find(new_s) != wordDict.end()
                && helper(s.substr(i+1), wordDict)) {
                mem[new_s] = true;
                return true;
            }
            mem[new_s] = false;
        }
        mem[new_s] = false;
        return false;
    }
private:
    unordered_map<string, bool> mem;
};
