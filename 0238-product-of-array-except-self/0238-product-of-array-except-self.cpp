class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n,1);
        for(int i=1; i<n; i++){
            ans[i] = ans[i-1] * nums[i-1];
        }
        
        int rightprod = 1;
        for(int i=0; i<n; i++){
            ans[n-i-1] *= rightprod;
            rightprod *= nums[n-i-1];
        }
        return ans;

    }
};