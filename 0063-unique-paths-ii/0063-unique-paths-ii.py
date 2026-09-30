class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: list[list[int]]) -> int:
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])

        dp = [[-1]*n for _ in range(m)]

        def dfs(row,col):
            if row == m-1 and col == n-1 and obstacleGrid[row][col] == 0:
                return 1
            
            if row >= m or col >= n:
                return 0

            if obstacleGrid[row][col] == 1:
                return 0
            
            if dp[row][col] != -1:
                return dp[row][col]

            dp[row][col] = dfs(row+1,col) + dfs(row,col+1)
            return dp[row][col]

        return dfs(0,0)