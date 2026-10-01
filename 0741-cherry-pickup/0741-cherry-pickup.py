class Solution:
    def cherryPickup(self, grid: list[list[int]]) -> int:
        
        # Reversing the second trip is completely valid, because we're
        # interested in the set of cells/path it visits, not the order
        # in which the cherries are picked.
        # So trip 2 will also be 0,0 -> n-1,n-1.

        n = len(grid)

        # 3D DP
        dp = [[[-1 for _ in range(n)] 
                 for _ in range(n)] 
                for _ in range(n)]

        def dfs(row1, col1, row2):

            # Since both people have taken the same number of steps:
            #
            # row1 + col1 = row2 + col2
            #
            # Therefore:
            col2 = row1 + col1 - row2

            # Invalid positions
            if row1 >= n or col1 >= n or row2 >= n or col2 >= n:
                return float('-inf')

            # Blocked cells
            if grid[row1][col1] == -1 or grid[row2][col2] == -1:
                return float('-inf')

            # Already calculated
            if dp[row1][col1][row2] != -1:
                return dp[row1][col1][row2]

            # Both have reached the destination 
            if row1 == n-1 and col1 == n-1 and row2 == n-1:
                return grid[row1][col1]

            result = grid[row1][col1] + grid[row2][col2]

            if row1 == row2 and col1 == col2:
                # Take the cherry only once
                result = grid[row1][col1]

            dr = [1, 0]   # down, right
            dc = [0, 1]

            best = float('-inf')

            # 2 choices for person 1 × 2 choices for person 2
            for i in range(2):
                for j in range(2):
                    best = max(
                        best,
                        dfs(
                            row1 + dr[i],
                            col1 + dc[i],
                            row2 + dr[j]
                        )
                    )

            dp[row1][col1][row2] = result + best

            return dp[row1][col1][row2]


        # Both people start at (0,0)
        return max(0, dfs(0, 0, 0))