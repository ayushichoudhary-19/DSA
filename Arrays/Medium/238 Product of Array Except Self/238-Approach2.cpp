class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int prod=1,n=nums.size();
        for(int i=0;i<n;i++){
            prod*=nums[i];
        }
        for(int i=0;i<n;i++){
            ans.push_back(prod/nums[i]);
        }

        return ans;
    }
};
