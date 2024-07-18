class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1,0));

        //base case
       for(int target=0; target<=amount;  target++){
        if(target%coins[0]==0)
            dp[0][target] = target/coins[0];
        else dp[0][target] = 1e9;
        }

        for(int idx=1; idx<n; idx++){
            for(int target=0; target<=amount; target++){
                int pick = 1e9;
                if(target>=coins[idx]) pick = 1 + dp[idx][target-coins[idx]];
                int nonpick = 0 + dp[idx-1][target];

                dp[idx][target]=min(pick,nonpick);
            }
        }
       
        int ans= dp[n-1][amount];

        if(ans >= 1e9)
        return -1;
        return ans;
    }
};