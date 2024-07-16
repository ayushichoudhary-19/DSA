class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));

        //BASE CASE
        dp[0][0] = grid[0][0];

        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++){
                if(col==0 && row==0) continue;
                else {
                int right=INT_MAX,up=INT_MAX;
                if(col>0) right = dp[row][col-1];
                if(row>0) up = dp[row-1][col];
                dp[row][col] = grid[row][col] + min(right,up); 
                }
            }
        }

        return dp[m-1][n-1];
    }
};