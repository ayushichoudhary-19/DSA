class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums)<=2:
            return len(nums)
        i=1
        cnt=1
        for j in range(1,len(nums)):
            if(nums[j]==nums[j-1]):
                cnt+=1
            else:
                cnt=1
            
            if cnt <= 2:
                nums[i] = nums[j]
                i += 1

        return i