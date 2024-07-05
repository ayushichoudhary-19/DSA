class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size=nums.size();
        int breakpoint=-1;
        for(int num=size-2; num>=0; num--){
            if(nums[num]<nums[num+1]){
                breakpoint=num;
                break;
            }
        }
        if(breakpoint==-1) {reverse(nums.begin(), nums.end()); return;};
        //now find smallest number greater than breakpoint value in rest array
        int smallestGreaterThanBreakpoint=INT_MAX;
        int swapIdx;
        for(int idx=breakpoint+1; idx<size; idx++){
            if(nums[idx]>nums[breakpoint]){
                if(smallestGreaterThanBreakpoint >= nums[idx]){
                    smallestGreaterThanBreakpoint = nums[idx];
                    swapIdx=idx;
                }
            }
        }
        swap(nums[breakpoint], nums[swapIdx]);
        reverse(nums.begin()+breakpoint+1, nums.end());

    }
    int nextGreaterElement(int n) {
        int n1=n;
        vector<int> nums;
        while(n>0){
            nums.push_back(n%10);
            n=n/10;
        }
        reverse(nums.begin(),nums.end());
        nextPermutation(nums);

        long long ans=0;
        for(auto num:nums){
            ans+=num;
            ans*=10;
        }
        ans=ans/10;
        
        cout<<ans<<"greater than "<<n;
        if(ans>=INT_MIN && ans<=INT_MAX && ans>n1) return ans;
        else return -1;
        
    }
};