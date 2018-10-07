bool isValidSudoku(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();
    unordered_set<pair<int,char>> rowmap;
    unordered_set<pair<int,char>> colmap;
    unordered_set<pair<int,char>> submap;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] != '.') {
                int row = i;
                int col = j;
                int sub = (i/3)*3 + (j/3);
                if(rowmap.find(pair<int,char>(row,board[i][j]) != rowmap.end()) ||
                colmap.find(pair<int,char>(col,board[i][j]) != colmap.end()) ||
                submap.find(pair<int,char>(sub,board[i][j]) != submap.end()))
                    return false;
                rowmap.push()
            }
        }
    }
}
