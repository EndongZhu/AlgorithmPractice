class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        left[0] = 1;
        for (int i = 1; i < n; i++) {
            int j = i-1;
            while (j >= 0 && heights[i] <= heights[j]) {
                j -= left[j];
            }
            left[i] = i-j;
        }
        right[n-1] = 1;
        for (int i = n-2; i >= 0; i--) {
            int j = i+1;
            while (j < n && heights[i] <= heights[j]) {
                j += right[j];
            }
            right[i] = j-i;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, heights[i] * (left[i]+right[i]-1));
        }
        return ans;
    }
private:
    int left[50001];
    int right[50001];
};
