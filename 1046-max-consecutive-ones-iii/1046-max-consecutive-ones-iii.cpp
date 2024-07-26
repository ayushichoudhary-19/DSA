class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int n = nums.size();
        int zeroCount = 0;
        int ans = 0;
        
        while (r < n) {
            if (nums[r] == 0) {
                zeroCount++;
            }
            
            while (zeroCount > k) {
                if (nums[l] == 0) {
                    zeroCount--;
                }
                l++;
            }
            
            ans = max(ans, r - l + 1);
            r++;
        }
        
        return ans;
    }
};
