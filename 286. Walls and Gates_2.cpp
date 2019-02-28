class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        height = rooms.size();
        if (height == 0) {
            return;
        }
        width = rooms[0].size();

        queue<int> que;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (rooms[i][j] == 0) {
                    que.push(zip(i, j));
                }
            }
        }

        while (!que.empty()) {
            int cur = que.front();
            que.pop();
            pair<int, int> pos = unzip(cur);
            int x = pos.first; int y = pos.second;
            if (x > 0 && rooms[x-1][y] == INT_MAX) {
                rooms[x-1][y] = rooms[x][y] + 1;
                que.push(zip(x-1, y));
            }
            if (x < height-1 && rooms[x+1][y] == INT_MAX) {
                rooms[x+1][y] = rooms[x][y] + 1;
                que.push(zip(x+1, y));
            }
            if (y > 0 && rooms[x][y-1] == INT_MAX) {
                rooms[x][y-1] = rooms[x][y] + 1;
                que.push(zip(x, y-1));
            }
            if (y < width-1 && rooms[x][y+1] == INT_MAX) {
                rooms[x][y+1] = rooms[x][y] + 1;
                que.push(zip(x, y+1));
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
};
