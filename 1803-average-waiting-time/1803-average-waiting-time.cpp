class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans=0;

        int currTime=customers[0][0];
        
        for(auto order: customers){
            currTime=max(currTime,order[0]);
            int freeAt = currTime + order[1];
            currTime = freeAt;
            ans = ans + (currTime - order[0]);
        }
        return ans/customers.size();
    }
};