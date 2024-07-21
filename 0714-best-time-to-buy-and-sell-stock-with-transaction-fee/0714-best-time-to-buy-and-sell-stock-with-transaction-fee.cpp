class Solution {
private:
    int solve(int idx, int buy, vector<int> &prices, vector<vector<int>> &dp, int fee) {
        // base case
        if (idx >= prices.size()) return 0;

        if (dp[idx][buy] != -1) return dp[idx][buy];

        int buythis = 0, sellthis = 0;
        if (buy) { 
            buythis = max(-prices[idx] + solve(idx + 1, 0, prices, dp, fee), 0 + solve(idx + 1, 1, prices, dp,fee));
        } 
        else {
            sellthis = max(prices[idx] - fee + solve(idx + 1, 1, prices, dp, fee), solve(idx + 1, 0, prices, dp,fee));
        }

        return dp[idx][buy] = max(buythis, sellthis);
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, dp, fee);
    }
};