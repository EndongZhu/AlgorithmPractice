
string removeInvalidParentheses(string s) {
    int cnt = 0;
    for(int i = 0;  i < s.size(); i++) {
        if(s[i] == '(')
            cnt++;
        else if(s[i] == ')')
            cnt--;
        if(cnt < 0) {
            s.erase(s.begin()+i);
            cnt++;
            i--;
        }
    }
    cnt = 0;
    for(int i = s.size()-1; i >= 0; i--) {
        if(s[i] == ')')
            cnt++;
        else if(s[i] == '(')
            cnt--;
        if(cnt < 0) {
            s.erase(s.begin()+i);
            cnt++;
        }
    }
    return s;
}
