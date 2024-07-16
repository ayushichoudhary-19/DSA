class Solution {
private:
    int solve(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp){
        //base case
        if(row==0 && col==0){
            return grid[row][col];
        }

        if(row<0 || col<0) return INT_MAX;

        if(dp[row][col]!=-1) return dp[row][col];

        int left = solve(grid,row,col-1,dp);

        int down = solve(grid,row-1,col,dp);

        return dp[row][col] =  grid[row][col] + min(left,down);

    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return solve(grid,m-1,n-1,dp);
    }
};