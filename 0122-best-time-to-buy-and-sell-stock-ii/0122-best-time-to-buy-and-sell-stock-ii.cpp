class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days=prices.size();
        vector<vector<int>> dp(days+1, vector<int> (2,-1));

        //base case
        dp[days][0] = 0;
        dp[days][1] = 0;

        for(int idx=days-1; idx>=0; idx--){
            for(int buy = 0; buy<2; buy++){
                int prof1=0, prof2=0;
                    //buy available
                    if(buy) {   
                    //buy today.        //skip buying
                         prof1 = max(-prices[idx] + dp[idx+1][0],  0 + dp[idx+1][1]);
                    }
                    else{
                        prof2= max(prices[idx] + dp[idx+1][1], 0 + dp[idx+1][0]);
                    }
                    dp[idx][buy] = max(prof1,prof2);
            }
        }
        return dp[0][1];
    }
};