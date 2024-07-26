class Solution {
private:
    int helper(vector<int>& nums, int k) {
        if(k<0) return 0;
        int l=0, r=0, n=nums.size();
        int sum=0;
        int count=0;

        while(r<n){
            sum+=nums[r];
            while(sum > k){
                sum-=nums[l];
                l++;
            }
            count += (r-l+1);
            r++;
        }
        return count;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2==1){
                nums[i]=1;
            }
            else nums[i]=0;
        }

        //now rest is same as: no. of binary subarrays with given sum
        return helper(nums, k) - helper(nums, k-1);
    }
};
