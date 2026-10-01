class Solution:
    def cherryPickup(self, grid: list[list[int]]) -> int:
        
        m, n = len(grid), len(grid[0])

        dp = [[[float('-inf')] * (n+1) for _ in range(n+1)] for _ in range(m+1)]

        #both will reach the same rows at the same time so only 1 is needed

        dp[0][0][n-1] = grid[0][0] + grid[0][n-1]

        for row in range(1,m):
            for col1 in range(n):
                for col2 in range(n):
                    gain = 0
                    if col1 == col2:
                        # add only once
                        gain = grid[row][col1]
                    else:
                        gain = grid[row][col1] + grid[row][col2]

                    dp[row][col1][col2] = gain + max(
                        dp[row - 1][col1][col2],
                        dp[row - 1][col1 + 1][col2],
                        dp[row - 1][col1][col2 + 1],
                        dp[row - 1][col1 + 1][col2 + 1],
                        dp[row - 1][col1][col2 - 1],
                        dp[row - 1][col1 - 1][col2],
                        dp[row - 1][col1 - 1][col2 - 1],
                        dp[row - 1][col1 - 1][col2 + 1],
                        dp[row - 1][col1 + 1][col2 - 1],
                    )

        ans = float('-inf')

        for col1 in range(n):
            for col2 in range(n):
                ans = max(ans,dp[m-1][col1][col2])

        return ans

