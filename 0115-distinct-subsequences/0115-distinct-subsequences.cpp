class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));

        // Initialize base cases
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;  // Any string can form an empty subsequence in exactly one way
        }

        // Fill the dp table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];  // Match or skip
                } else {
                    dp[i][j] = dp[i - 1][j];  // Skip
                }
            }
        }

        return dp[m][n];
    }
};
