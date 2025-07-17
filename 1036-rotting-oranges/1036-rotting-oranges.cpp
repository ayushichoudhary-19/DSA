class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int fresh = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                } else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        int time = 0;
        int cnt = 0;

        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);

            for(int i = 0; i < 4; i++) {
                int newr = r + drow[i];
                int newc = c + dcol[i];
                if(newr >= 0 && newr < n && newc >= 0 && newc < m &&
                   !vis[newr][newc] && grid[newr][newc] == 1) {
                    q.push({{newr, newc}, t + 1});
                    vis[newr][newc] = 1;
                    cnt++;
                }
            }
        }
        if(cnt != fresh) return -1;
        return time;
    }
};
