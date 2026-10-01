class Solution:
    def minFallingPathSum(self, matrix: list[list[int]]) -> int:

        m, n = len(matrix), len(matrix[0])

        # STATE:
        # prev[col] = minimum falling path sum
        # starting from the row below, at column col

        # Base case: last row
        prev = matrix[m - 1][:]

        for row in range(m - 2, -1, -1):

            curr = [float('inf')] * n

            for col in range(n):

                digleft = float('inf')
                digright = float('inf')

                if col > 0:
                    digleft = prev[col - 1]

                if col < n - 1:
                    digright = prev[col + 1]

                down = prev[col]

                curr[col] = matrix[row][col] + min(
                    digleft,
                    down,
                    digright
                )

            # Move to the next row
            prev = curr

        return min(prev)