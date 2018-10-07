int minSubArrayLen(int s, vector<int>& nums) {
    int hi = 0, lo = 0 ;
    int cur_sum = 0 ;
    int min_len = INT_MAX ;
    while (hi != nums.size()) {
        cur_sum += nums[hi] ;
        while(cur_sum >= s) {
            if(hi-lo+1 > min_len) {
                min_len = hi-lo+1 ;
            }
            cur_sum -= nums[lo] ;
            ++lo ;
        }
        ++hi ;
    }
    return min_len == INT_MAX ? 0 : min_len ;
}
