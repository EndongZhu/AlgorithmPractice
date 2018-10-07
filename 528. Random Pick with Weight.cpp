class Solution {
public:
    Solution(vector<int> w) {
        int total = 0;
        for(int i = 0; i < w.size(); i++) {
            total += w[i];
            reserve.push_back(total);
        }
    }

    int pickIndex() {
        int max_num = reserve[reserve.size()-1];
        int rand_number = 1+rand()%max_num;
        vector<int>::iterator iter = lower_bound(reserve.begin(),reserve.end(),rand_number);
        int res = iter - reserve.begin();
        return res;
    }
private:
    vector<int> reserve;
};
