class Solution:
    def minFallingPathSum(self, matrix: list[list[int]]) -> int:
        
        m, n = len(matrix), len(matrix[0])

        dp = [[float('inf')]* (n) for _ in range(m)]

        # base case
        # only one row
        # STATE: minimum sum starting at given row,col
        for col in range(n):
            dp[m-1][col] = matrix[m-1][col]

        for row in range(m-2,-1,-1):
            for col in range(n):
                digleft,down,digright = float('inf'),float('inf'),float('inf')

                if col > 0:
                    digleft = dp[row + 1][col - 1]

                if col < n-1:
                    digright = dp[row + 1][col + 1]

                down = dp[row + 1][col]
                dp[row][col] = matrix[row][col] + min(
                    digleft,
                    down,
                    digright
                )

        ans = float('inf')

        for col in range(n):
            ans = min(ans, dp[0][col])

        return ans