class Solution {
private:
    void bfs(int n, int m, vector<vector<int>> &vis, vector<vector<int>> &image,
             vector<vector<int>> &ans, int row, int col, int newColor, int originalColor) {

        vis[row][col] = 1;
        ans[row][col] = newColor;
        queue<pair<int, int>> q;
        q.push({row, col});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newrow = r + drow[i];
                int newcol = c + dcol[i];

                if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < m &&
                    vis[newrow][newcol] == 0 && image[newrow][newcol] == originalColor) {

                    q.push({newrow, newcol});
                    vis[newrow][newcol] = 1;
                    ans[newrow][newcol] = newColor;
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image,
                                  int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        int originalColor = image[sr][sc];

        if (originalColor == newColor) return image; 

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans = image;

        bfs(n, m, vis, image, ans, sr, sc, newColor, originalColor);
        return ans;
    }
};
