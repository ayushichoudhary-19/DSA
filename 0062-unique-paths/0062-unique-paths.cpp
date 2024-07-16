class Solution {
private:
    int solver(int row, int col,  vector<vector<int>> &dp){
        //base case
        if(row==0 && col==0) return 1;

        if(row<0 || col<0) return 0;

        if(dp[row][col]!=-1) return dp[row][col];

        int down = solver(row-1, col, dp);
        int left = solver(row,col-1, dp);

        return dp[row][col] = down+left;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return solver(m-1,n-1,dp);
    }
};