class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days=prices.size();

        vector<int> prev(2), curr(2);

        //base case
        prev[0] = 0;
        prev[1] = 0;

        for(int idx=days-1; idx>=0; idx--){
            for(int buy = 0; buy<2; buy++){
                int prof1=0, prof2=0;
                    //buy available
                    if(buy) {   
                    //buy today.        //skip buying
                         prof1 = max(-prices[idx] + prev[0],  0 + prev[1]);
                    }
                    else{
                        prof2= max(prices[idx] + prev[1], 0 + prev[0]);
                    }
                    curr[buy] = max(prof1,prof2);
            }
            prev = curr;
        }
        return prev[1];
    }
};