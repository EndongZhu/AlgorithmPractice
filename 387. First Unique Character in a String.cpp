int firstUniqChar(string s) {
    int mem[128] = {0};
    for(int i = 0; i < s.size(); i++) {
        mem[s[i]]++;
    }
    for(int i = 0; i < s.size(); i++) {
        if(mem[s[i]] == 1)
            return i;
    }
    return -1;
}
