class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size();
        if (n == 0) {
            return 0;
        }
        int k = days[0].size();
        memset(dp, 0, sizeof(int)*n*k);
        dp[0][0] = days[0][0];
        for(int i = 0; i < n; i++) {
            if(flights[0][i] == 1) {
                dp[i][0] = days[i][0];
            } else {
                dp[i][0] = -1;
            }
        }
        for (int t = 1; t < k; t++) {
            for (int i = 0; i < n; i++) {
                int max_days = dp[i][t-1];
                for (int j = 0; j < n; j++) {
                    if (flights[j][i]) {
                        max_days = max(max_days, dp[j][t-1]);
                    }
                }
                dp[i][t] = max_days == -1 ? -1 : max_days + days[i][t];
            }
        }
        int ans = 0;
        for  (int i = 0; i < n; i++) {
            ans = max(ans, dp[i][k-1]);
        }
        return ans;
    }
private:
    int dp[101][101];
};
