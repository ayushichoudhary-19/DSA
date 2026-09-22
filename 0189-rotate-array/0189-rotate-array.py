class Solution:

    def rotate(self, nums: list[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        def rev(l,r):
            while l<r:
                nums[l],nums[r] = nums[r],nums[l]
                l += 1
                r -= 1
        

        k = k % len(nums)
        rev(0,len(nums)-1)
        rev(0,k-1)
        rev(k,len(nums)-1)

