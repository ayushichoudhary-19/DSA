class Solution {
public:

    int maxrobamount(vector<int>& nums) {
        int n=nums.size();
        // vector<int> dp(n,-1);

        //base case
        int preprev=0, prev=nums[0], curr=0;

        for(int i=1; i<n; i++){
            int pick;
            if(i>1)
                 pick = preprev + nums[i];
            else pick = nums[1]; 

            int nonpick = prev;

           
            curr = max(pick,nonpick);
            preprev=prev;
            prev=curr;
        }
        return prev;


    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> nofirst, nolast;
        if(n==1) return nums[0];

        for(int i=0; i<n; i++){
            if(i!=0) nofirst.push_back(nums[i]);
            if(i!=n-1) nolast.push_back(nums[i]);
        }

        return max(maxrobamount(nofirst),maxrobamount(nolast));
    }
};