class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        curr_max = nums[0]
        curr_min = nums[0]
        ans = nums[0]

        for i in range(1, len(nums)):
            curr = nums[i]

            prev_max = curr_max
            prev_min = curr_min

            curr_max = max(curr, curr * prev_max, curr * prev_min)
            curr_min = min(curr, curr * prev_max, curr * prev_min)

            ans = max(ans, curr_max)

        return ans