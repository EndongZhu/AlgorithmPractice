string minWindow(string s, string t) {
    unordered_map mem ;
    for(auto i : t) {
        if(mem.find(i) != mem.end())
            mem[i]++ ;
        else
            mem[i] = 1 ;
    }
    int lo = 0, hi = 0, count = t.size() ;
    int head = 0, min_len = INT_MAX ;
    while(hi != s.end()) {
        if(mem.find(s[hi]) != mem.end()) {
            if(mem[s[hi]]-- > 0)
                --count ;
        }
        while(count == 0) {
            if(hi-lo+1 > min_len) {
                min_len = hi-lo+1 ;
                head = lo ;
            }
            if(mem.find(s[lo]) != mem.end()) {
                mem[s[lo]]++ ;
                if(mem[s[lo]] > 0)
                    ++count ;
            }
            ++lo ;
        }
        ++tail ;
    }
    return min_len == INT_MAX ? "" : s.substr(s.begin()+lo, min_len) ;
}
