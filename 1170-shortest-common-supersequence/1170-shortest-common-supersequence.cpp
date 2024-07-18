class Solution {
private:
vector<vector<int>> longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length()+1, vector<int> (text2.length()+1,-1));

        //shifting of index
        for(int i=0;i<=text1.size();i++) dp[i][0]=0; //here 0 means -1
        for(int i=0;i<=text2.size();i++) dp[0][i]=0;

        for(int idx1=1; idx1<=text1.size();idx1++){
            for(int idx2=1; idx2<=text2.size();idx2++){
                if(text1[idx1-1]==text2[idx2-1]) dp[idx1][idx2] =  1+dp[idx1-1][idx2-1];
                else dp[idx1][idx2]=max(dp[idx1-1][idx2], dp[idx1][idx2-1]);

        }
        }
        return dp;
    }


public:
    string shortestCommonSupersequence(string str1, string str2) {
		vector<vector<int>> dp = longestCommonSubsequence(str1,str2);
        int n=str1.length(), m=str2.length();

        string ans;
        int i=n, j=m;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans += str1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                ans += str1[i - 1];
                i--;
            } else {
                ans += str2[j - 1];
                j--;
            }
        }

        // Add remaining characters of str1
        while (i > 0) {
            ans += str1[i - 1];
            i--;
        }

        // Add remaining characters of str2
        while (j > 0) {
            ans += str2[j - 1];
            j--;
        }
         reverse(ans.begin(), ans.end());
        return ans;
    }
};