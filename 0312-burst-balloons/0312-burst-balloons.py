class Solution:
    def maxCoins(self, nums: list[int]) -> int:
    
        nums = [1] + nums + [1] # padding
        n = len(nums)

        dp = [[-1]*n for _ in range(n)]

        def dfs(i,j):

            if i+1 == j:
                #means only two ballons are left so there is nothing b/w them to burst
                # state here is burst every balloon b/w i and j

                return 0

            if dp[i][j] != -1:
                return dp[i][j]

            ans = float('-inf')
            tempAns = 0

            for k in range(i+1,j):
                tempAns = dfs(i,k) + dfs(k,j) + nums[i] * nums[k] * nums[j]

                ans = max(ans,tempAns)

            dp[i][j]=ans
            return dp[i][j]

        return dfs(0,n-1)            