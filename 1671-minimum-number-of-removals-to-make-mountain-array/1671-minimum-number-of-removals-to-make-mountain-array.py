class Solution:

    def minimumMountainRemovals(self, nums: list[int]) -> int:
        LIS = []
        LDS = []

        n = len(nums)
        def LeastIncSubsq():
            LIS = [1] * n

            for i in range(n):
                for j in range(i):
                    if nums[i] > nums[j]:
                        LIS[i] = max(LIS[i], 1 + LIS[j])

            return LIS

        LIS = LeastIncSubsq()
        
        print(LIS)

        print('_____')

        def LeastDecSubsq():
            LDS = [1] * n

            for i in range(n-1,-1,-1):
                for j in range(i+1,n):
                    if nums[i] > nums[j]:
                        LDS[i] = max(LDS[i], 1 + LDS[j])

            return LDS
        
        LDS = LeastDecSubsq()

        print(LDS)


        maxmountainlen = 0

        for i in range(n):
         if LIS[i] > 1 and LDS[i] > 1:
            maxmountainlen = max(maxmountainlen, LIS[i] + LDS[i] - 1)
        
        return n - maxmountainlen