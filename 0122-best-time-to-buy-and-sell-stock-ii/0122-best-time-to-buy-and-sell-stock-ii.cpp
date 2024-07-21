class Solution {
private:
    int solve(int idx, int buy, vector<int>& prices, vector<vector<int>> &dp){
        if(idx==prices.size()) return 0;

        if(dp[idx][buy]!=-1) return dp[idx][buy];


        int prof1=0, prof2=0;
        //buy available
        if(buy) {   
                    //buy today.    //skip buying
            prof1 = max(-prices[idx] + solve(idx+1, 0, prices,dp),  0 + solve(idx+1,1,prices,dp));
        }
        else{
            prof2= max(prices[idx] + solve(idx+1,1,prices,dp), 0 + solve(idx+1,0,prices,dp));
        }
        return dp[idx][buy] = max(prof1,prof2);
    }
public:
    int maxProfit(vector<int>& prices) {
        int days=prices.size();
        vector<vector<int>> dp(days, vector<int> (2,-1));
        return solve(0,1,prices,dp);
    }
};