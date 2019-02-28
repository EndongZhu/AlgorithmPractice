class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int>a, pair<int, int>b) {
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        });
        vector<int> dp;
        for (auto envelope : envelopes) {
            auto iter = lower_bound(dp.begin(), dp.end(), envelope.second);
            if (iter == envelopes.end()) {
                dp.push_back(envelope.second);
            } else {
                *iter = envelop.second;
            }
        }
        return dp.size();
    }
};
