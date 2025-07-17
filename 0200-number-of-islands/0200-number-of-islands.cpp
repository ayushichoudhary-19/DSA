class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis, int n, int m) {
        vis[row][col] = 1;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++) {
            int newr = row + drow[i];
            int newc = col + dcol[i];
            if(newr >= 0 && newr < n && newc >= 0 && newc < m &&
               !vis[newr][newc] && grid[newr][newc] == '1') {
                dfs(newr, newc, grid, vis, n, m);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid, vis, n, m);
                }
            }
        }
        return count;
    }
};
