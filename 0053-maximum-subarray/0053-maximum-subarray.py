class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        n = len(nums)
        [-2,1,-3,4,-1,2,1,-5,4]
        currsum = 0
        #when we pick nothing it gives maxsum 0 for [] so atleast that is a maxsum
        maxsum = float('-inf')

        for i in range(n):
            currsum += nums[i]
            maxsum = max(maxsum,currsum)
        
            if currsum < 0:
                currsum = 0
                
        
        return maxsum