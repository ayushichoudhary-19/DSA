class Solution {
private:
    int solve(int idx, vector<int>& coins, int amount,vector<vector<int>> &dp ){

        //base case
        if(idx==0) {
            if(amount%coins[0]==0) return amount/coins[0];
            else return 1e9;
        }

        if(dp[idx][amount] != -1) return dp[idx][amount];

        int pick = INT_MAX;
        if(amount >= coins[idx]) pick = 1 + solve(idx, coins, amount-coins[idx],dp);
        int nonpick = 0 + solve(idx-1, coins, amount, dp);

        return dp[idx][amount] = min(pick,nonpick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1,-1));
        int ans= solve(n-1,coins,amount,dp);

        if(ans >= 1e9)
        return -1;
        return ans;
    }
};