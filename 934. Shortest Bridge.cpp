class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size();
        if (m == 0) {
            return 0;
        }
        int n = A[0].size();
        height = m;
        width = n;
        queue<int> q;

        bool flag = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 1) {
                    q.push(zip(i,j));
                    A[i][j] = 0;
                    while (!q.empty()) {
                        int cur = q.front();
                        pair<int, int> pos = unzip(cur);
                        int x = pos.first;
                        int y = pos.second;
                        q.pop();
                        que.push(make_pair(cur, 0));
                        if(x-1 >= 0 && A[x-1][y] == 1) {
                            A[x-1][y] = 0;
                            q.push(zip(x-1, y));
                        }
                        if(x+1 < height && A[x+1][y] == 1) {
                            A[x+1][y] = 0;
                            q.push(zip(x+1, y));
                        }
                        if(y-1 >= 0 && A[x][y-1] == 1) {
                            A[x][y-1] = 0;
                            q.push(zip(x, y-1));
                        }
                        if(y+1 < width && A[x][y+1] == 1) {
                            A[x][y+1] = 0;
                            q.push(zip(x, y+1));
                        }
                    }
                    flag = true;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        while(!que.empty()) {
            pair<int, int> cur = que.front();
            que.pop();
            pair<int, int> pos = unzip(cur.first);
            int len = cur.second;
            int x = pos.first;
            int y = pos.second;
            if(visited.find(cur.first) != visited.end()) {
                continue;
            } else {
                visited.insert(cur.first);
            }
            if (A[x][y] == 1) {
                return len-1;
            }
            if (x > 0) {
                que.push(make_pair(zip(x-1, y), len+1));
            }
            if (x < height-1) {
                que.push(make_pair(zip(x+1, y), len+1));
            }
            if (y > 0) {
                que.push(make_pair(zip(x, y-1), len+1));
            }
            if (y < width-1) {
                que.push(make_pair(zip(x, y+1), len+1));
            }
        }

        return 0;
    }

    int zip(int i, int j) {
        return i*width + j;
    }

    pair<int, int> unzip (int num) {
        int a = num / width;
        int b = num % width;
        return make_pair(a, b);
    }

private:
    int height;
    int width;
    queue<pair<int, int> > que;
    unordered_set<int> visited;
};
