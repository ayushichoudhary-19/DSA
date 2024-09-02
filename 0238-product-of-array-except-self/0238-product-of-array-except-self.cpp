class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftprod(n,1), rightprod(n,1);

        for(int i=1; i<n; i++){
            leftprod[i] = nums[i-1] * leftprod[i-1];
            rightprod[n-i-1] = nums[n-i] * rightprod[n-i];
        }

        vector<int> ans(n);
        
        for(int i=0; i<n; i++){
            ans[i] = leftprod[i]*rightprod[i];
        }
        return ans;

    }
};