int maxProduct(vector<int>& nums) {
    int size = nums.size();
    if(size == 0)
        return 0 ;
    int max_dp[size+1] = {0};
    int min_dp[size+1] = {0};
    max_dp[0] = nums[0];
    min_dp[0] = nums[0];
    for(int i = 1; i < size; i++) {
        max_dp[i] = max(max(nums[i], nums[i] * max_dp[i-1]),
                        nums[i] * min_dp[i-1]);
        min_dp[i] = min(min(nums[i], nums[i] * max_dp[i-1]),
                        nums[i] * min_dp[i-1]);
    }
    int res = INT_MIN ;
    for(int i = 0; i < size; i++) {
        if(max_dp[i] > res) {
            res = max_dp[i];
        }
    }
    return res;
}
