class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        size = len(nums)
        prefixprod = [1]*size
        suffixprod = [1]*size

        ans = [1] * size

        for i in range(1,size):
            prefixprod[i] = prefixprod[i-1] * nums[i-1]
            suffixprod[size-i-1] = suffixprod[size-i] * nums[size-i]

        for i in range(size):
            ans[i] = prefixprod[i] * suffixprod[i]
        
        return ans

        