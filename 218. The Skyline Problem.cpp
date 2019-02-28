class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<long long> pq;
        unordered_map<int, int> mem;
        mem[0] = INT_MAX;
        pq.push(0);
        vector<pair<int, int>> ans;
        for (auto vec : buildings) {
            long long start = vec[0];
            long long end = vec[1];
            long long height = vec[2];
            if (!pq.empty()) {
                long long highest = pq.top();
                long long highest_tail = mem[highest];
                while (start > highest_tail) {
                    pq.pop();
                    long long sec_highest = pq.top();
                    long long sec_highest_tail = mem[sec_highest];
                    while (sec_highest_tail < highest_tail) {
                        pq.pop();
                        mem.erase(sec_highest);
                        sec_highest = pq.top();
                        sec_highest_tail = mem[sec_highest];
                    }
                    ans.push_back(make_pair(highest_tail, sec_highest));
                    highest = sec_highest;
                    highest_tail = sec_highest_tail;
                }
                if (height > highest) {
                    ans.push_back(make_pair(start, height));
                    while (highest_tail <= end) {
                        pq.pop();
                        mem.erase(highest);
                        highest = pq.top();
                        highest_tail = mem[highest];
                    }
                }
                pq.push(height);
                mem[height] = end;
            }
        }
        while (pq.size() > 1) {
            long long highest = pq.top();
            long long highest_tail = mem[highest];
            pq.pop();
            long long sec_highest = pq.top();
            long long sec_highest_tail = mem[sec_highest];
            while (highest_tail >= sec_highest_tail) {
                pq.pop();
                sec_highest = pq.top();
                sec_highest_tail = mem[sec_highest];
            }
            ans.push_back(make_pair(highest_tail, sec_highest))
        }
        return ans;
    }
};
