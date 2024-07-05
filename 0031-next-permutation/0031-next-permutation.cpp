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
};