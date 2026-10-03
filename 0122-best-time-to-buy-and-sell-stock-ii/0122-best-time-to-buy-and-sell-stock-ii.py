class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        

        n = len(prices)

        dp = [[-1]* 2 for _ in range(n)]

        def dfs(i,canbuy):

            if i == n :
                return 0


            if dp[i][canbuy] != -1:
                return dp[i][canbuy]

            profit = 0
            if canbuy:
                # can buy then i buy or not buy
                profit = max ( -prices[i] + dfs(i+1,0) , 0 + dfs(i+1,1) )

            else:
                # can sell or can not sell
                profit = max( prices[i] + dfs(i+1,1) , 0 + dfs(i+1,0))

            dp[i][canbuy] = profit
            return dp[i][canbuy]

        return dfs(0,1)