class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        count_map = set(nums)
        max_count = 0
        
        for n in count_map:
            if n + 1 not in count_map:
                count=1
                idx = n
                while(idx-1 in count_map):
                    count+=1
                    
                    idx-=1
                max_count=max(count,max_count)

        return max_count