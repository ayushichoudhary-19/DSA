class Solution {
private:
    int solve(vector<int>& nums, vector<int>& dp, int house){
        if(house<0) return 0;
        if(house==0) return nums[0];

        if(dp[house]!=-1) return dp[house];

        int pickThisHouse = nums[house] + solve(nums,dp,house-2);

        int skipThisHouse = 0 + solve(nums,dp,house-1);

        return dp[house] = max(pickThisHouse, skipThisHouse);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(nums,dp,n-1);
    }
};