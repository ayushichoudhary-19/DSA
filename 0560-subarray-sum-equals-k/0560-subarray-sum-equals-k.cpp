class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int n=nums.size();
        int count=0;
        int prefix=0;
        map[0]=1; //empty subarray
        
        for(int i=0; i<n; i++){
            prefix+=nums[i];
            if(map.find(prefix-k)!=map.end()){
                count+=map[prefix-k];
            }
            map[prefix]++;
        }
        return count;
    }
};