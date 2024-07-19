class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        //base cases 
        //we consider -1 to be at index 0 thus 1 on dp indexes are actually 0 on string indexes
        
        dp[0][0] = 1;
        //for i=0 &j=0 is done in above case case 
        for(int i=1; i<=m; i++){
            dp[i][0] = 0;
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = (p[j - 1] == '*') && dp[0][j - 1];
        }

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if (s[i-1] == p[j-1] || p[j-1] == '?') 
                        dp[i][j] = dp[i - 1][j - 1];
                else if (p[j-1] == '*') 
                        dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                else dp[i][j] = false;
            }
        }
        return dp[m][n];
        }
};
