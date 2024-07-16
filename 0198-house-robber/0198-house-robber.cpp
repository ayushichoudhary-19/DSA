class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);

        //base case
        dp[0] = nums[0];

        for(int i=1; i<n; i++){
            int pick;
            if(i>1)
                 pick = dp[i-2] + nums[i];
            else pick = nums[1]; 

            int nonpick = dp[i-1];

           
            dp[i] = max(pick,nonpick);
        }
        return dp[n-1];


    }
};