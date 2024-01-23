class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int sum=(n*(n+1))/2;
        int currsum=nums[0];
        int duplicate;
        for(int i=1;i<n;i++){
            currsum+=nums[i];
            if(nums[i-1]==nums[i])
            {
                duplicate=nums[i];
            }
        }
        return {duplicate,duplicate+sum-currsum};
    }
};