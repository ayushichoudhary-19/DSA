class Solution {
private:
    int helper(vector<int>& nums, int k) {
        if(k<0) return 0;
        int l=0, r=0, n=nums.size();
        int oddcount=0;
        int ans=0;

        while(r<n){
            if(nums[r]%2==1){
                oddcount++;
            }
            while(oddcount > k){
                if(nums[l] % 2 == 1) {
                    oddcount--;
                }
                l++;
            }
            ans += (r-l+1);
            r++;
        }
        return ans;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k-1);
    }
};
