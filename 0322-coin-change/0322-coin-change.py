class Solution:

    def coinChange(self, coins: list[int], amount: int) -> int:
        ans = float('inf')
        
        n = len(coins)
        dp = [[-1]*(n+1) for _ in range(amount+1)]

        def dfs(amount,index):
            nonlocal ans

            # base case?
            # minimuize the input: no coins in list to choose, amount sum is 0\
            if amount == 0:
                return 0

            # no coins left
            if index == n:
                return float('inf')

            # already solved
            if dp[amount][index] != -1:
                return dp[amount][index]

            pick = float('inf')

            # include current coin
            if coins[index] <= amount:
               pick = 1 + dfs(amount-coins[index],index)
            # don't include the coin
            dontpick = dfs(amount,index+1)

            dp[amount][index] = min(pick,dontpick)
            return dp[amount][index]

        ans = dfs(amount,0)
        
        return ans if ans!= float('inf') else -1