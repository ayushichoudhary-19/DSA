class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroat=-1;
        int n=nums.size();
        
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                zeroat=i;
                break;
            }
        }

        //no zero found 
        if(zeroat==-1) return;

        //before first zero all things are already fine so start from firdt zero
        for(int i=zeroat; i<n; i++){
            if(nums[i]!=0){
                //find a nonzero element and swap it with zero
                swap(nums[i],nums[zeroat]);
                //now nonzero is pointing to this new location
                zeroat++;
            }
        }
        return;
    }
};