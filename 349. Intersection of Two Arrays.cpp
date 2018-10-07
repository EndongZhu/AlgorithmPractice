vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int> mem ;
    vector<int> ans ;
    for(auto i : nums1) {
        if(mem.find(i) != mem.end())
            mem[i] = 1 ;
    }
    for(auto i : nums2) {
        if(mem.find(i) != mem.end())
            ans.push_back(i) ;
    }
    return ans ;
}
