static bool cmp(Interval& a, Interval& b) {
    return a.start > b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() <= 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> ans;
        ans.push_back(intervals[i]);
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i].start <= intervals[i-1].end) {
                int len = ans.size();
                ans[len-1].end = intervals[i].end;
            }
            else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
