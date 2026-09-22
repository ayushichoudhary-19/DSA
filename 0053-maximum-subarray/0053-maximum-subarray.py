class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        n = len(nums)
        curr = nums[0]
        best = nums[0]

        for i in range(1,n):
            curr = max(nums[i], curr + nums[i])
            best = max(curr, best)
            
        return best