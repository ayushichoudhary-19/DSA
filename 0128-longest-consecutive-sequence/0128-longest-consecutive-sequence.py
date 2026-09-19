class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        if len(nums) == 0:
            return 0
        nums.sort()
        count = 1
        maxcount = 1
        for i in range(1,len(nums)):
            if nums[i-1] == nums[i]-1:
                count += 1
                maxcount = max(maxcount,count)
            
            elif nums[i-1] != nums[i]:
                count = 1

        return maxcount