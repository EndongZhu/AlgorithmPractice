class Solution {
public:
    vector<vector<bool>> visited;
    int m;
    int n;

    bool valid(int i, int j, vector<vector<char>>& board) {
        bool flag = true;
        if (i >= 0 && i < m && j >= 0 && j < n) {
            flag = board[i][j] != 'X';
        }
        return !visited[i][j] && flag;
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        if (m <= 2) {
            return;
        }
        n = board[0].size();
        if (n <= 2) {
            return;
        }


    }

    bool dfs(int i, int j, vector<vector<char>>& board) {
        if ()
    }
};
