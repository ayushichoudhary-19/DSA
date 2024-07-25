class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        int ans = 0;
        
        // Fill the first row and column of dp based on matrix
        for (int row = 0; row < m; row++) {
            dp[row][0] = matrix[row][0];
            ans += dp[row][0]; // Accumulate count for squares of size 1x1
        }
        for (int col = 0; col < n; col++) {
            dp[0][col] = matrix[0][col];
            ans += dp[0][col]; // Accumulate count for squares of size 1x1
        }

        ans-=dp[0][0]; //as this was repeated twice in row and col both
        
        // Fill the rest of the dp table
        for (int row = 1; row < m; row++) {
            for (int col = 1; col < n; col++) {
                if (matrix[row][col] == 1) {
                    // Compute the largest square ending at (row, col)
                    dp[row][col] = min({dp[row-1][col-1], dp[row-1][col], dp[row][col-1]}) + 1;
                    ans += dp[row][col]; // Add the number of new squares formed
                }
            }
        }
        
        return ans;
    }
};
