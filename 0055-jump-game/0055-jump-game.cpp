class Solution {
public:
    bool canJump(vector<int>& nums) {
       vector<int> dp(nums.size(),-1);

        //base case
        dp[nums.size()-1] = 1;

       for(int idx=nums.size()-2; idx>=0; idx--){
            bool jump=false;
            for(int i=1; i<=nums[idx]; i++){
            jump = jump || dp[idx+i];
            }
            dp[idx] = jump;
       }
       return dp[0];
    }
};