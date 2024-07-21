class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2,0));
        vector<int> prev(2,0), curr(2,0), preprev(2,0);

        for(int idx = n-1; idx>=0; idx--){
            for(int buy = 0; buy<2; buy++){
                int buythis = 0, sellthis = 0;
            if (buy) { 
            buythis = max(-prices[idx] + prev[0], 0 + prev[1]);
        } 
        else {
            sellthis = max(prices[idx] + preprev[1], 0 + prev[0]);
        }

            curr[buy] = max(buythis, sellthis);
            }
            preprev = prev;
            prev = curr;
            }


        return curr[1];
        }
};
