class Solution {
private:
    int longestCommonSubseq(string s1,string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        
        //base case
        for(int i=0; i<=n; i++){
            dp[i][0]=0;
        }
        for(int i=0; i<=m; i++){
            dp[0][i]=0;    
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
public:

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int totalLen = m+n;
        return totalLen - 2*longestCommonSubseq(word1,word2);
    }
};