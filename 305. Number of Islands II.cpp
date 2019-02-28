class Solution {
public:
    void UnionFind() {
        for (int i = 0; i < m * n; i++) {
            parents.push_back(-1);
            ranks.push_back(0);
        }
    }

    int index(int a, int b) {
        return a * n + b;
    }

    int Find(int idx) {
        if (parents[idx] == -1) {
            return -1;
        }
        if(parents[idx] != idx) {
            parents[idx] = Find(parents[idx]);
        }
        return parents[idx];
    }

    void Union(int x, int y) {
        int x_parent = Find(x);
        int y_parent = Find(y);
        if (ranks[x_parent] > ranks[y_parent]) {
            parents[y_parent] = x_parent;
        } else if (ranks[y_parent] > ranks[x_parent]) {
            parents[x_parent] = y_parent;
        } else {
            parents[y_parent] = x_parent;
            ranks[x_parent] += 1;
        }
    }


    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        this->m = m;
        this->n = n;
        UnionFind();
        int cnt = 0;
        vector<int> ans;
        for (auto position : positions) {
            int a = position.first;
            int b = position.second;
            int idx = index(a, b);
            if (parents[idx] == -1) {
                parents[idx] = idx;
                ranks[idx] = 1;
                cnt++;
            }
            if (a-1 >= 0 && Find(index(a-1, b)) != -1) {
                if (Find(idx) != Find(index(a-1, b))) {
                    Union(idx, index(a-1, b));
                    cnt--;
                }
            }
            if (a + 1 < m && Find(index(a+1, b)) != -1) {
                if (Find(idx) != Find(index(a+1, b))) {
                    Union(idx, index(a+1, b));
                    cnt--;
                }
            }
            if (b-1 >= 0 && Find(index(a, b-1)) != -1) {
                if (Find(idx) != Find(index(a, b-1))) {
                    Union(idx, index(a, b-1));
                    cnt--;
                }
            }
            if (b+1 < n && Find(index(a, b+1)) != -1) {
                if (Find(idx) != Find(index(a, b+1))) {
                    Union(idx, index(a, b+1));
                    cnt--;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }

private:
    vector<int> parents;
    vector<int> ranks;
    int m;
    int n;
};
