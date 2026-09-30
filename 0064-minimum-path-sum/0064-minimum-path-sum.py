class Solution:
    def minPathSum(self, grid: list[list[int]]) -> int:
        INF = float('inf')
        ans = float('inf')
        m = len(grid)
        n = len(grid[0])

        dp = [[-1]*n for _ in range(m)]

        def dfs(row,col):
            nonlocal ans

            if row == m-1 and col == n-1:
                return grid[m-1][n-1]
            
            if row >= m or col >=n:
                return float('inf')

            if dp[row][col] != -1:
                return dp[row][col]

            dp[row][col] = grid[row][col]+min(dfs(row+1,col),
                        dfs(row,col+1)
                    )
            return dp[row][col]

        return dfs(0,0)