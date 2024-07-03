class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<4) return 0;

        sort(nums.begin(), nums.end());

        int ans=INT_MAX;

        for(int left=0; left<4; left++){
            int right = nums.size() - 4 + left;
            ans=min(ans,nums[right]-nums[left]);
        }
        return ans;
    }
};