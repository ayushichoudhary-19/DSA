class Solution {
private:
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &vis, int n, int m) {
        vis[i][j] = 1;
        int deltaI[4] = {-1, 0, 1, 0};
        int deltaJ[4] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int newI = i + deltaI[k];
            int newJ = j + deltaJ[k];
            if (newI >= 0 && newI < n && newJ >= 0 && newJ < m && grid[newI][newJ] == '1' && vis[newI][newJ] == 0) {
                dfs(newI, newJ, grid, vis, n, m);
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    dfs(i, j, grid, vis, n, m);
                }
            }
        }
        return cnt;
    }
};
