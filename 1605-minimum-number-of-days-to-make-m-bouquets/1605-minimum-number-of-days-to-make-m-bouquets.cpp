class Solution {
public:
    int minDays(vector<int>& nums, int m, int k) {
        if (nums.empty() || k <= 0 || m <= 0 || k > nums.size()) return -1;

        int low = INT_MAX, high = INT_MIN;
        int res=-1;
        for(int num:nums){
            low = min(low, num);
            high = max(high, num);
        }

        while(low <= high){
            int possdays = low + (high - low)/2;
            int kAdj = 0;
            int adjCnt = 0;

            for(int num:nums){
                if(num <= possdays){
                    adjCnt++;
                }
                else{
                    kAdj += (adjCnt/k);
                    adjCnt = 0;
                }
            }

            kAdj += (adjCnt/k);
            
            int noOfBuq = kAdj;

            if(noOfBuq >= m){
                res = possdays;
                //find more lesser no. of days
                high = possdays - 1;
            }
            else low = possdays + 1;
        }

        return res;
    }
};