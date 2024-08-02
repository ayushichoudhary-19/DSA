class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totones = 0;
        for(int n : nums) {
            totones += n;
        }

        int size = nums.size();
        int zerocnt = 0;
        for(int i = 0; i < totones; i++) {
            zerocnt += nums[i] == 0;
        }

        nums.insert(nums.end(), nums.begin(), nums.end());

        int windowsize = totones;
        int ans = zerocnt;

        for(int i = totones; i < size + totones; i++) {
            zerocnt += nums[i] == 0;
            zerocnt -= nums[i - totones] == 0;
            ans = min(ans, zerocnt);
        }
        
        return ans;
    }
};
