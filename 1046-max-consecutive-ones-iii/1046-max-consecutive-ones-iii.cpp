class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int K=k;
        int ans=INT_MIN;
        int cnt=0;
        int l=0, r=0;
        int n=nums.size();
        while(l<=r && r<n){
            if(nums[r]==1) {
            r++;
            cnt++;
            }
            else if(nums[r]==0 && K>0){
                r++;
                cnt++;
                K--;
            }
            else{
                //k is exhausted and 0 is found
                ans=max(ans,cnt);
                l++;
                r=l;
                cnt=0;
                K=k;
            }
        }
        return max(ans,cnt);
    }
};