class Solution:
    def minFallingPathSum(self, matrix: list[list[int]]) -> int:
        
        m, n = len(matrix), len(matrix[0])

        dp = [[float('inf')]* (n) for _ in range(m)]
        def dfs(row, col):
            if col < 0 or col >= n:
                return float('inf')

            if row == m - 1:
                return matrix[row][col]

            if dp[row][col] != float('inf'):
                return dp[row][col]

            dp[row][col] = matrix[row][col] + min(
                dfs(row + 1, col - 1),
                dfs(row + 1, col),
                dfs(row + 1, col + 1)
            )
            return dp[row][col]

        ans = float('inf')

        for col in range(n):
            ans = min(ans, dfs(0, col))

        return ans