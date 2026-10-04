class Solution:
    def maxProfit(self, k: int, prices: list[int]) -> int:
        
        n = len(prices)
        dp = [[-1]* (2*k) for _ in range(n)]

        def dfs(i,transaction):
            if i == n :
                return 0

            if transaction == 2*k:
                return 0
                

            if dp[i][transaction] != -1:
                return dp[i][transaction]

            canbuy = False
            if transaction%2 == 0:
                canbuy = True
            
            profit = 0
            if canbuy:
                # can buy then i buy or not buy
                profit = max ( -prices[i] + dfs(i+1,transaction+1) , 0 + dfs(i+1,transaction) )

            else:
                # can sell or can not sell
                profit = max( prices[i] + dfs(i+1,transaction+1) , 0 + dfs(i+1,transaction))

            dp[i][transaction]= profit
            return dp[i][transaction]

        return dfs(0,0)

        