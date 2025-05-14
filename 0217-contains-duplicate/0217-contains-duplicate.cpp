class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());


        return num_set.size() != nums.size();
    }
};