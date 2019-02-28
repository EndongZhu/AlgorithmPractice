class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n  == 0) {
            return 0;
        }
        int dp[n][n][n];
        memset(dp, 0, sizeof(int)*n*n*n);
        for (int t = 0; t < 2*n; t++) {
            for (int r1 = 0; r1 < n; r1++) {
                int c1 = t - r1;
                if (c1 < 0 || c1 >= n) {
                    continue;
                }
                for (int r2 = 0; r2 < n; r2++) {
                    int c2 = t - r2;
                    if (c2 < 0 || c2 >= n) {
                        continue;
                    }
                    int num = 0;
                    if (grid[r1][c1] == 1) {
                        num++;
                    }
                    if (grid[r2][c2] == 1 && r2 != r1 && c2 != c1) {
                        num++;
                    }
                    int a = r1 > 0 ? dp[r1-1][c1][r2] : 0;
                    int b = r1 > 0 && r2 > 0 ? dp[r1-1][c1][r2-1] : 0;
                    int c = c1 > 0 ? dp[r1][c1-1][r2] : 0;
                    int d = c1 > 0 && r2 > 0 ? dp[r1][c1-1][r2-1] : 0;
                    dp[r1][c1][r2] = max(max(a, b), max(c, d)) + num;
                    if (grid[r1][c1] == -1 || grid[r2][c2] == -1) {
                        dp[r1][c1][r2] = 0;
                    }
                }
            }
        }
        return dp[n-1][n-1][n-1];
    }
};
