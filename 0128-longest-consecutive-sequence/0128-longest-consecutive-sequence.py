class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        hashset = set(nums)

        count = 0
        maxcount = 0

        for num in hashset:
            if num-1 in hashset:
                # this is not the starting of the consequetive seq
                continue
            
            else:
                temp = num
                count = 1
                while temp + 1 in hashset:
                    count += 1
                    temp = temp + 1
                
                maxcount = max(maxcount,count)

        return maxcount 