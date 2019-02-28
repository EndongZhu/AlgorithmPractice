class Solution {
public:
    int numSquares(int n) {
        vector<int> nums;
        for (int i = 1 ; i*i <= n; i++) {
            nums.push_back(i*i);
        }
        int m = nums.size();
        int dp[n+1];
        for (int i = 0; i <= n; i++) {
            dp[i] = INT_MAX;
        }
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                if (i - nums[j] >= 0 && dp[i-nums[j]]+1 < dp[i]) {
                    dp[i] = dp[i-nums[j]]+1;
                }
            }
        }
        return dp[n];
    }
};
