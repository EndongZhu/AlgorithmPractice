bool backspaceCompare(string S, string T) {
    string convertS = convert(S);
    string convertT = convert(T);
    return convertT == convertS;
}

string convert(string s) {
    int len = s.size();
    if(len <= 1)
        return s;
    int cnt = 0;
    string ans = "";
    for(int i = len-1; i >= 0; i--) {
        if(s[i] == '#')
            cnt++;
        else {
            if(cnt == 0)
                ans = s[i] + ans;
            else
                cnt--;
        }
    }
    return ans;
}
