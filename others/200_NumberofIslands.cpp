class Solution {
private:
    void dfs_visit(int n, int m, int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        visited[x][y] = true;
        if (x - 1 >= 0 && !visited[x-1][y] && grid[x-1][y] == '1') {
            dfs_visit(n, m, x-1, y, grid, visited);
        }
        if (y - 1 >= 0 && !visited[x][y-1] && grid[x][y-1] == '1') {
            dfs_visit(n, m, x, y-1, grid, visited);
        }
        if (x + 1 < n && !visited[x+1][y] && grid[x+1][y] == '1') {
            dfs_visit(n, m, x+1, y, grid, visited);
        }
        if (y + 1 < m && !visited[x][y+1] && grid[x][y+1] == '1') {
            dfs_visit(n, m, x, y+1, grid, visited);
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        int num_islands = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // Visit all unvisited nodes '1'.
                if (!visited[i][j] && grid[i][j] == '1') {
                    dfs_visit(n, m, i, j, grid, visited); 
                    ++num_islands;
                }
            }
        }
        
        return num_islands;
    }
};
