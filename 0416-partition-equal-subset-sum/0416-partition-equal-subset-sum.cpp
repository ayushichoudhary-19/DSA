class Solution {
private:
        bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        
        // base case: target 0 for any index is true (empty subset)
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        
        if (arr[0] <= sum) {
            dp[0][arr[0]] = true;
        }
        
        // fill the dp array
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= sum; j++) {
                bool pick = (j >= arr[i]) ? dp[i - 1][j - arr[i]] : false;
                bool nonpick = dp[i - 1][j];
                
                dp[i][j] = pick || nonpick;
            }
        }
        
        return dp[n - 1][sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto num:nums){
            sum+=num;
        }
        if(sum%2!=0) return false;
        return isSubsetSum(nums,sum/2);
    }
};