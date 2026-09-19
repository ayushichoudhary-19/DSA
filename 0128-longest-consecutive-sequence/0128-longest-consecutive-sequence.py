class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        if len(nums) == 0:
            return 0
        
        numsset = set(nums)
      
        maxcount = 0

        for num in numsset:
            if num-1 in numsset:
                continue
            else:
                # this num is start of the sequence
                temp = num
                count = 1
                while temp+1 in numsset:
                    count += 1
                    temp += 1
                
                maxcount = max(maxcount,count)

        return maxcount