class Solution:
    def maxProfit(self, k: int, prices: list[int]) -> int:
        
        n = len(prices)
        dp = [[[-1]* 2 for _ in range(k+1)] for _ in range(n)]

        def dfs(i,times,canbuy):

            if i == n :
                return 0

            if times == k:
                return 0

            if dp[i][times][canbuy] != -1:
                return dp[i][times][canbuy]

            profit = 0
            if canbuy:
                # can buy then i buy or not buy
                profit = max ( -prices[i] + dfs(i+1,times,0) , 0 + dfs(i+1,times,1) )

            else:
                # can sell or can not sell
                profit = max( prices[i] + dfs(i+1,times+1,1) , 0 + dfs(i+1,times,0))

            dp[i][times][canbuy] = profit
            return dp[i][times][canbuy]

        return dfs(0,0,1)

        