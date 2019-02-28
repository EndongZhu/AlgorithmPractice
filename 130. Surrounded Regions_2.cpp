class Solution {
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if (m == 0) {
            return;
        }
        n = board[0].size();
        memset(visited, 0, sizeof(bool)*1001*1001);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && board[i][j] == 'O')
                    dfs(board, i, j);
            }
        }
        return;
    }

    bool dfs(vector<vector<char>>& board, int i, int j) {
        bool flag = false;
        if (fetch(board, i-1, j) || fetch(board, i+1, j)
        || fetch(board, i, j-1) || fetch(board, i, j+1)) {
            return true;
        }
        if (i-1 >= 0 && !visited[i-1][j] && board[i-1][j] == 'O') {
            flag = flag || dfs(board, i-1, j);
        }
        if (i+1 < m && !visited[i+1][j] && board[i+1][j] == 'O') {
            flag = flag || dfs(board, i+1, j);
        }
        if (j-1 >= 0 && !visited[i][j-1] && board[i][j-1] == 'O') {
            flag = flag || dfs(board, i, j-1);
        }
        if (j+1 < n && !visited[i][j+1] && board[i][j+1] == 'O') {
            flag = flag || dfs(board, i, j+1);
        }
        if (!flag) {
            board[i][j] = 'X';
        }
        return flag;
    }

    bool fetch(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return true;
        }
        return false;
    }
private:
    int m;
    int n;
    bool visited[1001][1001];
};
