vector<int> findAnagrams(string s, string p) {
    int map[128] = {0};
    for(int i = 0; i < p.size(); i++) {
        map[p[i]]++;
    }
    vector<int> ans;
    int head = 0, tail = p.size()-1;
    int count = 0;
    for(int i = head; i <= tail; i++) {
        if(map[s[i]]-- <= 0)
            count++;
    }
    while(tail < s.size()) {
        if(count == 0)
            ans.push_back(head);
        if(++map[s[head++]] == 0)
            count--;
        if(map[s[head]-- == 0)
            count++;
        if(++map[s[tail++]] == 0)
            count--;
        if(map[s[tail]]-- == 0)
            count++;
    }
    return ans ;
}
