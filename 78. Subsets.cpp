class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(num.begin(), nums.end());
        queue<set<int>> que;
        que.push(set<int>());
        vector<vector<int>> ans;
        while(!que.empty()) {
            set<int> cur = que.front();
            que.pop();
            ans.push_back(vector<int>(cur.begin(), cur.end()));
            if (cur.size() == nums.size()) {
                break;
            }
            int tail = *(cur.end()-1);
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > tail) {
                    set<int> new_set(cur);
                    new_set.insert(nums[i]);
                    que.push(new_set);
                }
            }
        }
    }
};
