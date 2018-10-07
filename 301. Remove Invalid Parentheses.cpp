bool isValid(string &s) {
    if(s == "")
        return true ;
    int cnt = 0 ;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            ++cnt ;
        else if (s[i] == ')') {
            --cnt ;
            if(cnt < 0)
                return false ;
        }
    }
    return cnt == 0 ;
}

vector<string> removeInvalidParentheses(string s) {
    vector<string> ans ;
    int ans_len = -1 ;
    queue<string> que ;
    unordered_map<string, int> flag ;
    que.push(s) ;
    while(!que.empty()) {
        string cur = que.front() ;
        que.pop() ;
        if(cur < ans_len)
            break ;
        if(isValid(cur)) {
            ans_len = cur.size() ;
            ans.push_back(cur) ;
        }
        for(int i = 0; i < cur.size(); i++) {
            string new_str = cur ;
            new_str.erase(new_str.begin()+i) ;
            if(flag[new_str] != 1) {
                que.push(new_str) ;
                flag[new_str] = 1 ;
            }
        }
    }
    return ans ;
}
