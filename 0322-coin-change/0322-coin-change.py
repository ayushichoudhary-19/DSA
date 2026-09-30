class Solution:

    def coinChange(self, coins: list[int], amount: int) -> int:

        n = len(coins)
        INF = float('inf')

        # dp[i][a] = minimum number of coins needed
        # to make amount a using coins from index i onward.
        dp = [[INF] * (amount + 1) for _ in range(n + 1)]

        # Base case: amount 0 requires 0 coins
        for i in range(n + 1):
            dp[i][0] = 0

        # Fill table
        for i in range(n - 1, -1, -1):
            for a in range(1, amount + 1):

                # Don't pick coin i
                dp[i][a] = dp[i + 1][a]

                # Pick coin i
                if coins[i] <= a:
                    dp[i][a] = min(
                        dp[i][a],
                        1 + dp[i][a - coins[i]]
                    )

        return dp[0][amount] if dp[0][amount] != INF else -1