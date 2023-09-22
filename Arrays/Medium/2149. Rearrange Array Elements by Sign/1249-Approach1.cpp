class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(ans[j]==0){
                        if(nums[i]>0 && j%2==0){
                          ans[j]=nums[i];
                        break;
                    }
                    else if(nums[i]<0 && j%2!=0){
                        ans[j]=nums[i];
                        break;
                    }
                    else{
                        if(ans[j+1]==0){
                            ans[j+1]=nums[i];
                              break;
                        }
                    }
                }
            }
        }

        return ans;
    }
};