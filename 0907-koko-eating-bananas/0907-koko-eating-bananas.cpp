class Solution {
public:
    int minEatingSpeed(vector<int>& nums, int h) {
        int low = 1, high = *max_element(nums.begin(), nums.end());

        while(low <= high){
            int possibleK = low + (high - low)/2;
            long long possHours = 0;
            for(int num:nums){
                possHours += ceil((double)(num)/(double)(possibleK));
            }

            if(possHours > h){
                //more than h hours are being taken so increase the rate k
                low = possibleK + 1;
            }
            else{
                //rate is lesser or equal to h, reduce space to find a lower k to find minimum k rate
                high = possibleK - 1;
            }
        }
        return low;
    }
};