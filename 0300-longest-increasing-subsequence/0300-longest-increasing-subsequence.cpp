class Solution {
private:
    int solve(int idx, int prev, vector<int> &nums, vector<vector<int>> &dp){
        if(idx==nums.size()) return 0;

        if(prev!=-1 && dp[idx][prev]!=-1) return dp[idx][prev];

        int take = 0;
        if(prev==-1 || nums[prev] < nums[idx] ) take = 1 + solve(idx+1, idx, nums, dp);
        int nontake = 0 + solve(idx+1, prev, nums, dp);

        if (prev != -1) {
            dp[idx][prev] = max(take, nontake);
            return dp[idx][prev];
        } else {
            return max(take, nontake);
        }
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int> (n,-1));
        return solve(0,-1,nums,dp);
    }
};