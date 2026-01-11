class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums)==1:
            return 1
        i,j=0,1
        for j in range(len(nums)):
            if(nums[j]!=nums[i]):
                i+=1
                nums[i] = nums[j]
        return i+1 
