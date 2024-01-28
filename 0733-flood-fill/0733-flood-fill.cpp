class Solution {
private:
    void dfs(vector<vector<int>>& image,vector<vector<int>>& grid, int sr, int sc, int color, int initcolor) {
        grid[sr][sc] = color;
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];
        if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && image[nrow][ncol] == initcolor && grid[nrow][ncol] != color) {
            dfs(image, grid, nrow, ncol, color, initcolor);
        }
    }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // make a copy of the original image
        vector<vector<int>> grid = image;

        // now traverse over the grid and change the color
        int initcolor = grid[sr][sc];
        dfs(image,grid, sr, sc, color, initcolor);
        return grid;
    }
};
