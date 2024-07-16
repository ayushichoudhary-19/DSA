class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        int minSum = INT_MAX;
        
        //base case
        for(int col=0; col<n; col++){
            dp[0][col]=matrix[0][col];
        }

        for(int row=1; row<n; row++){
            for(int col=0; col<n; col++){
                int left = (col > 0) ? dp[row-1][col-1] : INT_MAX;
                int right = (col < n-1) ? dp[row-1][col+1] : INT_MAX;
                int up = dp[row-1][col];

                dp[row][col] = matrix[row][col] + min({up, left, right});  
            }
        }

         for(int col=0; col<n; col++){
            minSum = min(minSum,dp[n-1][col]);
        }


        return minSum;
    }
};