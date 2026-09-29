class Solution:
    def minCostClimbingStairs(self, cost: list[int]) -> int:
        n = len(cost)
        dp = [0] * (n+1)
        
        dp[0] = cost[0]
        dp[1] = cost[1]

        for i in range(2,n):
            dp[i] = min(dp[i-1],dp[i-2]) + cost[i]

        
        dp[n] = min(dp[n-1],dp[n-2])

        return dp[n]