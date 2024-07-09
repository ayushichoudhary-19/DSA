class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt=0;
        for(auto num:arr){
            if(num%2==0) cnt=0;
            else cnt++;

            if(cnt==3) return true;
        }
        return false;
    }
};