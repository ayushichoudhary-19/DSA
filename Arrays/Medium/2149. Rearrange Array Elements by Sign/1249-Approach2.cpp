class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        //pointer p points to even index and q points to odd index
        int p=0,q=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans[p]=nums[i];
                p+=2;
            }
            else{
                ans[q]=nums[i];
                q+=2;            }
        }

        return ans;
    }
};