class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        height = rooms.size();
        if (height == 0) {
            return;
        }
        width = rooms[0].size();

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (rooms[i][j] == INT_MAX) {
                    bfs(rooms, zip(i, j));
                    visited.clear();
                    //return;
                }
            }
        }

    }

    void bfs(vector<vector<int>>& rooms, int start) {
        queue<pair<int, int>> que;
        que.push(make_pair(start, 0));
        while(!que.empty()) {
            pair<int, int> cur = que.front();
            que.pop();
            if (visited.find(cur.first) != visited.end()) {
                continue;
            } else {
                visited.insert(cur.first);
            }
            int len = cur.second;
            pair<int, int> origin = unzip(start);
            pair<int, int> pos = unzip(cur.first);
            if(rooms[pos.first][pos.second] == 0) {
                rooms[origin.first][origin.second] = min(rooms[origin.first][origin.second], len);
                break;
            }
            if (pos.first > 0 && rooms[pos.first-1][pos.second] != -1) {
                que.push(make_pair(zip(pos.first-1, pos.second), len+1));
            }
            if (pos.first < height-1 && rooms[pos.first+1][pos.second] != -1) {
                que.push(make_pair(zip(pos.first+1, pos.second), len+1));
            }
            if (pos.second > 0 && rooms[pos.first][pos.second-1] != -1) {
                que.push(make_pair(zip(pos.first, pos.second-1), len+1));
            }
            if (pos.second < width-1 && rooms[pos.first][pos.second+1] != -1) {
                que.push(make_pair(zip(pos.first, pos.second+1), len+1));
            }
        }
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
    unordered_set<int> visited;
};
