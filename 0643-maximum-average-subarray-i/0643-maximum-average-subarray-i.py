class Solution:
    def findMaxAverage(self, nums: list[int], k: int) -> float:
        
        currsum = 0
        for i in range(k):
            currsum += nums[i]

        maxavg = currsum/k

        l,r = 0,k
        while r<len(nums):
            currsum -= nums[l]
            l += 1
            currsum += nums[r]
            r += 1

            maxavg = max(maxavg , currsum/k)

        return maxavg
        