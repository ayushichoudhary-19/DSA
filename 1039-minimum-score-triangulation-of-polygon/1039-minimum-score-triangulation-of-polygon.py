class Solution:
    def minScoreTriangulation(self, values: list[int]) -> int:
        n = len(values)

        dp = [[-1]*n for _ in range(n)]
        def dfs(i,j):
            ans = float('inf')

            if j-i+1 < 3:
                return 0

            if dp[i][j] != -1:
                return dp[i][j]
    
            tempans = 0
            for k in range(i+1,j):
                tempans = dfs(i,k) + dfs(k,j) + values[i]*values[k]*values[j]
                ans = min(ans,tempans)

            dp[i][j] = ans
            return dp[i][j]

        return dfs(0,n-1)