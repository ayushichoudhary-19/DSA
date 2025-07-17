class Solution {
public:
    void solve(vector<vector<char>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((i == 0 || i == n - 1 || j == 0 || j == m - 1) &&
                   mat[i][j] == 'O' && vis[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = 1;
                    mat[i][j] = 'Z';
                }
            }
        }

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int d = 0; d < 4; d++) {
                int nrow = row + delrow[d];
                int ncol = col + delcol[d];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                   mat[nrow][ncol] == 'O' && vis[nrow][ncol] == 0) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                    mat[nrow][ncol] = 'Z';
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 'Z') mat[i][j] = 'O';
                else mat[i][j] = 'X';
            }
        }
    }
};
