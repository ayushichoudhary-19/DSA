class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        i,j = 0,0
        minlen = float('inf')
        currsum = 0
        while j<len(nums):
            while currsum < target and j<len(nums):
                currsum += nums[j]
                j += 1
            
            while currsum >= target:
                minlen = min(minlen, j-i)
                currsum -= nums[i]
                i += 1

        return 0 if minlen == float('inf') else minlen
