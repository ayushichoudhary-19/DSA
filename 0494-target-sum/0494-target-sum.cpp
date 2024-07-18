class Solution {
private:
    int findTargetSumWaysUtil(vector<int>& nums, int target, int idx, vector<vector<int>> &dp){
        //base case
        if(idx==-1){
            if(target==0) return 1;
            else return 0;
        }

        // Check bounds before accessing dp table
        if (target < -1000 || target > 1000) {
            return 0;
        }

        if(dp[idx][target+1000]!=-1) return dp[idx][target+1000];
        
        int pos = findTargetSumWaysUtil(nums,target-nums[idx],idx-1,dp);
        int neg = findTargetSumWaysUtil(nums,target+nums[idx],idx-1,dp);

        return dp[idx][target+1000] = pos+neg;

    } 
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (2001, -1));


        //as target can be negative so we make indexing balanced out to start from 0 
        //try on paper for target range -2 to 2 and you';ll understand why +1000
        return findTargetSumWaysUtil(nums,target,n-1,dp);
    }
};