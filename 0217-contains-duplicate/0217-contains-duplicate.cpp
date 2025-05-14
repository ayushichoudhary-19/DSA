class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> freqmap;

        for(auto& num: nums){
            if(freqmap[num]) return true;
            freqmap[num]++;
        }
        return false;
    }
};