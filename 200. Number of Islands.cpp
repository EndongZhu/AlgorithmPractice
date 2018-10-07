bool visited[1001][1001] ;

void dfs(vector<vector<char>>& grid, int& n, int& m, int i, int j) {
    visited[i][j] = 1 ;
    if(i-1 >= 0 && !visited[i-1][j] && grid[i-1][j] == '1')
        dfs(grid, n, m, i-1, j) ;
    if(i+1 < n && !visited[i+1][j] && grid[i+1][j] == '1')
        dfs(grid, n, m, i+1, j) ;
    if(j-1 >= 0 && !visited[i][j-1] && grid[i][j-1] == '1')
        dfs(grid, n, m, i, j-1) ;
    if(j+1 < m && !visited[i][j+1] && grid[i][j+1] == '1')
        dfs(grid, n, m, i, j+1) ;
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size() ;
    if(n == 0)
        return 0 ;
    int m = grid[0].size() ;

    int cnt = 0 ;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j] && grid[i][j] == '1') {
                ++cnt ;
                dfs(grid, n, m, i, j) ;
            }
        }
    }
    return cnt ;
}
