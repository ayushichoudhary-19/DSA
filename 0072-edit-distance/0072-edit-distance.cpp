class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length(), n=word2.length();
        vector<vector<int>> dp(m+1, vector<int> (n+1,0));

        //base cases
        for(int idx1=0; idx1<=m; idx1++){
            //where ever my idx1 is there if idx 2 is 0 (actually -1) then      store that idx1+1 deletions from word1 needed to match 
            dp[idx1][0] = idx1;
        }
        for(int idx2=0; idx2<=n; idx2++){
            dp[0][idx2] = idx2;
        }

        for(int idx1=1; idx1<=m; idx1++){
            for(int idx2=1; idx2<=n; idx2++){
                if(word1[idx1-1]==word2[idx2-1]){
                    dp[idx1][idx2] = 0 + dp[idx1-1][idx2-1];
                }

                else{
                    int insertions = 1 + dp[idx1][idx2-1];
                    int deletions = 1 + dp[idx1-1][idx2];
                    int replacements = 1 + dp[idx1-1][idx2-1];

                    dp[idx1][idx2] = min({insertions, deletions, replacements});
                }
            }
        }
        return dp[m][n];
    }
};