string countAndSay(int n) {
    string cur = "1" ;
    for(int i = 1; i < n; i++) {
        string new_str = "";
        for(int j = 0; j <= cur.size();) {
            int pos = j+1;
            while(cur[pos] == cur[pos-1] && pos < cur.size())
                pos++;
            int count = pos-j;
            new_str = new_str + (string(1,'0'+count) + string(1,s[j]));
            j = pos;
        }
        cur = new_str;
    }
    return cur;
}
