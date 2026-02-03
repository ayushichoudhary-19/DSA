class Solution:
    def canJump(self, nums: List[int]) -> bool:
        goal = len(nums) - 1 
        for currpos in range(len(nums)-2,-1,-1):
            if(currpos + nums[currpos] >= goal):
                goal = currpos

        return True if goal == 0 else False