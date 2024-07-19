class Solution {
private:
    int solve(int idx1, int idx2, string word1, string word2, vector<vector<int>> &dp){
        //base case
        if(idx1<0) //if word1 exhausts earlier then we need to insert more to word1 for matching with remaining word2 characters
        //if idx2 is at index say 1, then we need to insert 2 elements that match index 0 and index 1 of word2. so idx2+1 insertions are needed
        {
            return idx2+1;
        }

        if(idx2<0) //then we have found the match of word2 but some extra are left in word1 so delete those characters
        {
            return idx1+1;
        }

        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

        if(word1[idx1]==word2[idx2]){
            //it's a match so go ahead;
            return dp[idx1][idx2] = 0 + solve(idx1-1, idx2-1, word1, word2,dp);
        }
        else{
            int insertions = 1 + solve(idx1, idx2-1, word1, word2,dp);
            int deletions = 1 + solve(idx1-1, idx2, word1, word2,dp);
            int replaces = 1 + solve(idx1-1,idx2-1, word1, word2,dp);

            return dp[idx1][idx2] = min({insertions, deletions, replaces});
        }

    }
public:
    int minDistance(string word1, string word2) {
        int m=word1.length(), n=word2.length();
        vector<vector<int>> dp(m+1, vector<int> (n+1,-1));
        return solve(m-1,n-1,word1,word2, dp);
    }
};