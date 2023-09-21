class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,1);
        int prod=1;

    //nums: 1,2,3,4
    //left hand side cumilative multiplication
       for(int i=1;i<n;i++){
           prod*=nums[i-1];
           ans[i]=prod;
       } 
    //ans: 1,1,2,6

    prod=1;
    //right hand side cumulative multiplication
    for(int i=n-1;i>=0;i--){
        ans[i]*=prod;
        prod*=nums[i];
    }
    //ans: 24 12 8 6

        return ans;
    }
};