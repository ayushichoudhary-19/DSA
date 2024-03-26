class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Marking non-positive numbers as n+1
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0)
                nums[i] = n + 1;
        }

        // Marking positive numbers' presence by flipping the sign
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }

        // Finding the first missing positive
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0)
                return i + 1;
        }

        // If all positive integers from 1 to n are present, return n+1
        return n + 1;
    }
};
