class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        // We use n+1 to handle the case where idx is n and prev is -1
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int prev = idx - 1; prev >= -1; prev--) {
                int take = 0;
                if (prev == -1 || nums[prev] < nums[idx]) {
                    take = 1 + dp[idx + 1][idx + 1];
                }
                int nontake = dp[idx + 1][prev + 1];

                dp[idx][prev + 1] = max(take, nontake);
            }
        }
        
        // Return the result for the case where idx is 0 and prev is -1
        return dp[0][0];
    }
};
