class Solution {
private:
    int solve(int i, int j, string s, string t, vector<vector<int>> &dp){
        //base case
        if(j==0) return 1; //found everything from end to start of target string
        if(i==0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i-1]==t[j-1]){
            int match = solve(i-1, j-1, s, t, dp);
            int skip = solve(i-1, j, s, t, dp);
            return dp[i][j] = match + skip;
        }
        // else have to skip when not matched
        return dp[i][j] = solve(i-1,j,s,t,dp);
    }
public:
    int numDistinct(string s, string t) {
        int m=s.length(), n=t.length();
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));

        return solve(m,n,s,t,dp);
    }
};