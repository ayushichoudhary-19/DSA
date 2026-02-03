class Solution:
    def jump(self, nums: List[int]) -> int:
        near = 0
        far = 0
        jumps = 0
        while far < len(nums)-1:
            farthest = 0 # to track farthest in this range we can go
            for i in range(near, far+1):
                farthest = max(farthest, i + nums[i])
            near = far + 1
            far = farthest
            jumps += 1
        
        return jumps



        [2,3,0,1,4]
