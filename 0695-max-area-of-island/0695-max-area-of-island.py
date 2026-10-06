class Solution:
    def maxAreaOfIsland(self, grid: list[list[int]]) -> int:
        
        m = len(grid)
        n = len(grid[0])

        delx = [0,1,0,-1]
        dely = [-1,0,1,0]

        maxarea = 0

        def dfs(i,j):

            grid[i][j] = 0
            area = 1

            for k in range(4):
                newx = i+delx[k]
                newy = j+dely[k]

                if newx >= 0 and newx<m and newy >= 0 and newy < n:
                    newnode = grid[newx][newy]
                    if newnode == 1:
                        area += dfs(newx, newy)

            return area
                    
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    maxarea = max(maxarea,dfs(i,j))
        
        return maxarea