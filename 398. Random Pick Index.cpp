class Solution {
public:
    Solution(vector<int> nums) {
        reserve = nums;
    }

    int pick(int target) {
        int res = -1;
        int count = 0;
        for(int i = 0; i < reserve.size(); i++) {
            if(reserve[i] == target) {
                count++;
                if(rand()%count == 0){
                    res = i;
                }
            }
        }
        return res;
    }
private:
    vector<int> reserve;

};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
