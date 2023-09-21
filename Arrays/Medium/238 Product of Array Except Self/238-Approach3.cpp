class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        vector<int> leftprod(n,0);
        vector<int> rightprod(n,0);
        int prod=1;

        //array to store the left products of each index
        leftprod[0]=1;
        for(int i=1;i<n;i++){
            prod*=nums[i-1];
            leftprod[i]=prod;
        }

        prod=1;

        //array to store the right products of each index
        rightprod[n-1]=1;
        for(int i=n-2;i>=0;i--){
            prod*=nums[i+1];
            rightprod[i]=prod;
        }

        for(int i=0;i<n;i++){
            ans.push_back(leftprod[i]*rightprod[i]);
        }
        

        return ans;
    }
};
