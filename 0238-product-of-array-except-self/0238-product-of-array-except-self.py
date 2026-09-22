class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        size = len(nums)

        ans = [1] * size

        for i in range(1,size):
            #storing prefix prod in ans
            ans[i] = ans[i-1] * nums[i-1]

        # Multiply by suffix products
        suffix = 1

        for i in range(size-1,-1,-1):
            ans[i] *= suffix
            suffix *= nums[i]

        return ans