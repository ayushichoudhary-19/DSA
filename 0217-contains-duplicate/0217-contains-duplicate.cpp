class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> freqmap;

        for(auto& num: nums){
            freqmap[num]++;
        }

        for(auto it=freqmap.begin(); it!=freqmap.end(); it++){
            if(it->second >= 2) return true;
        }
        return false;
    }
};