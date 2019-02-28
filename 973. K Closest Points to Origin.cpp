class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        quickSelect(points, 0, points.size()-1, K);
        vector<vector<int>> ans;
        for (int i = 0; i < points.size(); i++) {
            ans.push_back(points[i]);
        }
        return ans;
    }

    void quickSelect(vector<vector<int>>& points, int start, int end, int K) {
        int len = end - start + 1;
        int idx = start + (rand() % len);
        points[idx].swap(points[start]);
        int ptr1 = start;
        int ptr2 = end;
        while (ptr1 < ptr2) {
            while(distance(points[ptr1]) <= distance(points[start]) && ptr1 < ptr2) {
                ptr1++;
            }
            while(distance(points[ptr2]) > distance(points[start]) && ptr1 < ptr2) {
                ptr2--;
            }
            points[ptr1].swap(points[ptr2]);
        }
        if (distance(points[ptr1]) <= distance(points[start])) {
            points[start].swap(points[ptr1]);
        } else {
            points[start].swap(points[ptr2]);
        }
        if (ptr1 == K-1) {
            return;
        } else if (ptr1 > K-1){
            quickSelect(points, start, ptr1-1, K - 1);
        } else {
            quickSelect(points, ptr1+1, end, K - 1 - ptr1);
        }
    }

    int distance(vector<int> &point) {
        return point[0]*point[0] + point[1]*point[1];
    }
};
