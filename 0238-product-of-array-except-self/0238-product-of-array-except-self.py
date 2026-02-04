class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        leftProd = n*[1]
        rightProd = n*[1]
        ans = n*[1]
        for i in range(0,n):
            leftProd[i] = leftProd[i-1] * nums[i] if i>0 else nums[i]
            if i != 0:
                rightProd[n-i] = rightProd[n-i+1] * nums[n-i] if i>1 else nums[n-i]

        for i in range(n):
            a = leftProd[i-1] if i>=1 else 1
            b = rightProd[i+1] if i <= n-2 else 1
            ans[i] = a*b
        
        return ans

