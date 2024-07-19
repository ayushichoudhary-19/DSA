class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf=0, minBuyPrice=prices[0];
        int n=prices.size();
        for(int i=1; i<n; i++){
            int sellAt = prices[i];
            int prof = sellAt - minBuyPrice;
            maxProf = max(maxProf, prof);
            minBuyPrice = min(minBuyPrice,prices[i]);
        }
        return maxProf;
    }
};