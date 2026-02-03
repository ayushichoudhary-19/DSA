class Solution:
    def canJump(self, nums: List[int]) -> bool:
        currpos = len(nums) - 2 #curr index who's max jump we check
        goal = len(nums) - 1 #pos where we want to check reach
        while goal > 0 and currpos >= 0:
            if(currpos + nums[currpos] >= goal):
                goal = currpos
            #if from currpos we can't reach goal with max jump
            # maybe from any max jump from prev indexes we can
            # so we do not end the loop here


            currpos-=1

        return True if goal == 0 else False