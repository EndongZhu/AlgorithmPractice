int totalFruit(vector<int>& tree) {
    int lo = 0, hi = 0;
    int ans = INT_MIN;
    unordered_map<int, int> mem;
    int cnt = 0;
    while(hi < tree.size()) {
        mem[tree[hi]] = mem.find(tree[hi]) == mem.end() ? 1 : mem[tree[hi]]+1;
        if(mem[tree[hi]] == 1) {
            cnt++;
        }
        if(cnt <= 2) {
            ans = max(ans, hi-lo+1);
        }
        while(cnt > 2) {
            mem[tree[lo]]--;
            if(mem[tree[lo]] == 0) {
                cnt--;
            }
            lo++;
        }
        hi++;
    }
    return ans;
}
