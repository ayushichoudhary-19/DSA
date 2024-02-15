class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        
       int size= nums.size();
       long long ans=-1;
       long long prefixsum=0;
        
// we sort the array to apply greedy
        sort(nums.begin(),nums.end());

        
// compare prefsum with each of the next elements and keep adding if valid
        for(int i=0;i<size;i++){
            if(prefixsum>nums[i]) ans=prefixsum+nums[i];
            prefixsum+=nums[i];
        }
        return ans;
    }
};