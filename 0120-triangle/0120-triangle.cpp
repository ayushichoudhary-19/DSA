class Solution {
private:
    int solve(vector<vector<int>>& triangle, int m, int row, int col, vector<vector<int>>& dp){
        
        //base case
        if(row==m-1) return triangle[row][col];

        if(col > row+1) return INT_MAX;
        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        
        int next = solve(triangle, m, row+1, col, dp);
        int adj = solve(triangle, m, row+1, col+1, dp);
        
        return dp[row][col] = triangle[row][col] + min(next, adj);

    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();

        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solve(triangle, m, 0, 0, dp);


    }
};