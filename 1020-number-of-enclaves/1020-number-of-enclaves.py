class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])

        delx = [0,1,0,-1]
        dely = [-1,0,1,0]

        count = 0

        def dfs(x,y):
            newx = x
            newy = y
            for k in range(4):
                newx = x + delx[k]
                newy = y + dely[k]

                if newx >= 0 and newx < m and newy>=0 and newy < n and grid[newx][newy] == 1:
                    grid[newx][newy] = -1
                    dfs(newx,newy)
        
        #traverse the 4 corners and do not count them at the end
        i,j = 0,0
        for i in range(m):
            if grid[i][j] == 1:
                grid[i][j] = -1
                dfs(i,j)

        j = n-1
        for i in range(m):
            if grid[i][j] == 1:
                grid[i][j] = -1
                dfs(i,j)

        i = 0
        for j in range(n):
            if grid[i][j] == 1:
                grid[i][j] = -1
                dfs(i,j)

        i = m-1
        for j in range(n):
            if grid[i][j] == 1:
                grid[i][j] = -1
                dfs(i,j)

        # count all the 1'es which are not hashed that is not connected to boundry 1

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    count += 1

        return count

