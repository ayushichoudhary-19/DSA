class Solution:

    def numIslands(self, grid: List[List[str]]) -> int:
        m = len(grid)
        n = len(grid[0])

        delx = [0,1,0,-1]
        dely = [-1,0,1,0]

        def dfs(i, j, grid):
            grid[i][j] = '#'

            for k in range(4):
                newi = i + delx[k]
                newj = j + dely[k]

                if 0 <= newi < m and 0 <= newj < n and grid[newi][newj] == '1':
                    dfs(newi, newj, grid)

        count = 0

        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    count += 1
                    dfs(i, j, grid)

        return count