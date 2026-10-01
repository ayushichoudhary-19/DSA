class Solution:
    def minPathSum(self, grid: list[list[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dp = [[0] * n for _ in range(m)]

        dp[0][0] = grid[0][0]

        for col in range(1, n):
            dp[0][col] = dp[0][col - 1] + grid[0][col]

        for row in range(1, m):
            dp[row][0] = dp[row - 1][0] + grid[row][0]

        for row in range(1, m):
            for col in range(1, n):
                dp[row][col] = grid[row][col] + min(
                    dp[row - 1][col],
                    dp[row][col - 1]
                )

        return dp[m - 1][n - 1]