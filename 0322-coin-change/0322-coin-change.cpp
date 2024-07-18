class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> prev(amount+1,0), curr(amount+1,0);

        //base case
       for(int target=0; target<=amount;  target++){
        if(target%coins[0]==0)
            prev[target] = target/coins[0];
        else prev[target] = 1e9;
        }

        for(int idx=1; idx<n; idx++){
            for(int target=0; target<=amount; target++){
                int pick = 1e9;
                if(target>=coins[idx]) pick = 1 + curr[target-coins[idx]];
                int nonpick = 0 + prev[target];

                curr[target]=min(pick,nonpick);
            }
            prev=curr;
        }
       
        int ans= prev[amount];

        if(ans >= 1e9)
        return -1;
        return ans;
    }
};