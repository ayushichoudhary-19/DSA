class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        string s1=s;
        //for not changing input string, we do not use rev fun but do manually
        string s2;
        for(int i=n-1; i>=0; i--){
            s2+=s[i];
        }

        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        
        //base case
        for(int i=0; i<=n; i++){
            dp[i][0]=0;
            dp[0][i]=0;    
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[n][n];
    }
};