class Solution {
public:
    int maxDistance(vector<int> &nums, int k) {


        sort(nums.begin(), nums.end());
        
        int ans = 0;
        
        int n = nums.size();

        int low = 1, high = nums[n - 1] - nums[0];

        while(low <= high){
            int maintain = low + (high - low)/2;

            int cowcnt = 1;
            int prevcow=nums[0];
            bool canWePlace = false;
            for(int num:nums){
                if(num - prevcow >= maintain) {
                    cowcnt++;
                    prevcow = num;
                }

                if(cowcnt >= k) {
                    canWePlace = true;
                    ans = maintain;
                   break;
                }
            }
            if(canWePlace) low = maintain + 1; //as we have to find max we move ahead of mid
            else high = maintain - 1;
        }
        return high;
    }
};