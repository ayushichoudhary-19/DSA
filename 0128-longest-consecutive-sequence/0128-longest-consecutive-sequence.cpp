class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> set;

        for(auto& num:nums){
            set.insert(num);
        }

        int maxCnt = 0;
        
        for(auto& num:set){
            if(set.find(num-1)==set.end()){
                int cnt = 1;
                int x = num;
                while(set.find(x+1)!=set.end()){
                    cnt++;
                    x++;
                }
                maxCnt = max(maxCnt, cnt);
            }
        }
        return maxCnt;
    }
};