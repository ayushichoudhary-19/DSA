class Solution {
private:
    int helper(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int count = 0;
        int l=0, r=0, n=nums.size();
        int sum=0;
        while(r<n){
            sum+=nums[r];
            while(sum > goal){
                sum-=nums[l];
                l++;
            }
            count+= (r-l+1);
            r++;
        }
        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return helper(nums,goal) - helper(nums,goal-1);
    }
};