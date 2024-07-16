class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();

        vector<vector<int>> dp(m,vector<int> (n,0));

        //base case
        for(int col=n-1; col>=0; col--){
            dp[n-1][col]=triangle[n-1][col];
        }

        for(int row=n-2; row>=0; row--){
            for(int col=row; col>=0; col--){
                int prev = dp[row+1][col];
                int adj = dp[row+1][col+1];
                
                dp[row][col] = triangle[row][col] + min(prev, adj);
            }
        }
        return dp[0][0];

    }
};