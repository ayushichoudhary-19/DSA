class Solution {
public:
    int solve(vector<int> &nums, int idx, int prev, vector<vector<int>> &dp){
        //base case
        if(idx==nums.size()) return 0;

        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        int take = INT_MIN;
        if( prev==-1 || nums[idx]>nums[prev]) take = 1 + solve(nums,idx+1,idx, dp);

        int nontake = solve(nums,idx+1,prev,dp);

        return dp[idx][prev+1] = max(take,nontake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(nums,0,-1,dp);
    }
};