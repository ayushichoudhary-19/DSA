class Solution {
private:
    int solve(int idx, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp){
        //base case
        if(cap==0) return 0;
        if(idx==prices.size()) return 0;
        if (dp[idx][buy][cap] != -1) return dp[idx][buy][cap];

        int buythis = 0, sellthis=0;
        if(buy){
            buythis = max(-prices[idx] + solve(idx+1, 0, cap, prices,dp), 0 + solve(idx+1, 1, cap, prices,dp));
        }
        else{
            sellthis = max(prices[idx] + solve(idx+1, 1, cap-1, prices,dp), 0 + solve(idx+1, 0, cap, prices,dp));
        }
        return dp[idx][buy][cap] = max(sellthis,buythis);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        
        return solve(0, 1, 2, prices,dp);
    }
};