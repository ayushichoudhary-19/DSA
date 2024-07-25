class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1), hash(n);
        int maxi=INT_MIN;
        for(int idx=0; idx<n; idx++){
            for(int prev=0; prev<idx; prev++){
                if(nums[prev]< nums[idx]){
                    dp[idx] = max(dp[idx], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[idx]);
        }
        return maxi;
    }
};
