int trap(vector<int>& height) {
    int len = height.size();
    int left_dp[len] = {0};
    int right_dp[len] = {0};
    left_dp[0] = height[0];
    for (int i = 1; i < len; i++) {
        left_dp[i] = max(height[i], left_dp[i-1]);
    }
    right_dp[len-1] = height[len-1];
    for (int i = len-2; i >= 0; i--) {
        right_dp[i] = max(height[i], right_dp[i+1]);
    }
    int ans = 0;
    for(int i = 0; i < len; i++) {
        ans += min(left_dp[i], right_dp[i])-height[i];
    }
    return ans;
}
