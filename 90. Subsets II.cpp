class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(num.begin(), nums.end());
        queue<vector<int>> que;
        que.push(vector<int>());
        vector<vector<int>> ans;
        while(!que.empty()) {
            vector<int> cur = que.front();
            que.pop();
            ans.push_back(cur);
            if (cur.size() == nums.size()) {
                break;
            }
            int tail = cur.empty() ? INT_MAX : cur.back();
            int cnt = cur.count(tail);
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > tail || (nums[i] == tail && cnt-- == 0)) {
                    vector<int> new_vec(cur);
                    new_vec.push_back(nums[i]);
                    que.push(new_vec);
                }
            }
        }
    }
};
