class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> hashmap;
        int count = 0;
        int prefixSum=0;
        hashmap[0] = 1;
        for(int i=0; i<nums.size(); i++){
            prefixSum+=nums[i];
            if(hashmap.find(prefixSum-goal)!=hashmap.end()){
                //we found 
                count+=hashmap[prefixSum-goal];
            }
            hashmap[prefixSum]++;
        }
        return count;
    }
};