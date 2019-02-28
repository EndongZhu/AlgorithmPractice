class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> v;
        for (auto num : nums) {
            v.push_back((double) num);
        }
        return dfs(v);
    }

    bool dfs(vector<double> nums) {
        if (nums.size() == 1) {
            return abs(nums[0] - 24.0) <= 0.001;
        }
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            for (int j = i+1; j < len; j++) {
                vector<double> new_nums (nums);
                double a = nums[i];
                double b = nums[j];
                new_nums.erase(new_nums.begin()+i);
                new_nums.erase(new_nums.begin()+j-1);
                new_nums.push_back(a+b);
                if (dfs(new_nums)) {
                    return true;
                } else {
                    new_nums.pop_back();
                }
                new_nums.push_back(a-b);
                if (dfs(new_nums)) {
                    return true;
                } else {
                    new_nums.pop_back();
                }
                new_nums.push_back(b-a);
                if (dfs(new_nums)) {
                    return true;
                } else {
                    new_nums.pop_back();
                }
                new_nums.push_back(a*b);
                if (dfs(new_nums)) {
                    return true;
                } else {
                    new_nums.pop_back();
                }
                if (a != 0) {
                    new_nums.push_back(b/a);
                    if (dfs(new_nums)) {
                        return true;
                    } else {
                        new_nums.pop_back();
                    }
                }
                if (b != 0) {
                    new_nums.push_back(a/b);
                    if (dfs(new_nums)) {
                        return true;
                    } else {
                        new_nums.pop_back();
                    }
                }
            }
        }
        return false;
    }
};
