class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //find the breakpoint
        int breakpoint=-1;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
          if(nums[i]<nums[i+1]){
            breakpoint=i;
            break;
          }  
        } 
        if(breakpoint==-1){reverse(nums.begin(),nums.end());return;}
        
        //find least greater of element at the breakpoint
        int leastgreater=-1; 
        int leastGvalue=101;
        for(int i=n-1;i>breakpoint;i--){
            if(nums[i]>nums[breakpoint]){
                if(nums[i]<leastGvalue){
                    leastgreater=i;
                    leastGvalue=nums[i];
                }
            }
        }

        //now swap breakpoint with leastgreater
        swap(nums[breakpoint],nums[leastgreater]);
        
        //reverse everything after the breakpoint
        reverse(nums.begin()+breakpoint+1,nums.end());
return;
}
};
