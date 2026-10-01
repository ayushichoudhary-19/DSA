class Solution:
    def cherryPickup(self, grid: list[list[int]]) -> int:
        
        m, n = len(grid), len(grid[0])

        dp = [[[-1] * (n) for _ in range(m)] for _ in range(m)]

        #both will reach the same rows at the same time so only 1 is needed
        def dfs(row,col1,col2):

            if col1 < 0 or col1 >= n or row < 0 or row >=m or col2 < 0 or col2 >= n:
                return float('-inf')
            
            if row == m-1:
                if col1 == col2:
                    # add only once
                    return grid[row][col1]
                
                return grid[row][col1] + grid[row][col2]

            if dp[row][col1][col2] != -1:
                return dp[row][col1][col2]

            gain = 0

            if col1 == col2:
                # add only once
                gain = grid[row][col1]

            else:
                gain = grid[row][col1] + grid[row][col2]

            dp[row][col1][col2] = gain + max(
                dfs(row+1,col1,col2),
                dfs(row+1,col1+1,col2),
                dfs(row+1,col1,col2+1),
                dfs(row+1,col1+1,col2+1),
                dfs(row+1,col1,col2-1),
                dfs(row+1,col1-1,col2),
                dfs(row+1,col1-1,col2-1),
                dfs(row+1,col1-1,col2+1),
                dfs(row+1,col1+1,col2-1),
            )

            return dp[row][col1][col2]

        return dfs(0, 0, n - 1)


