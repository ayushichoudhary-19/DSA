class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m = len(grid)
        n = len(grid[0])

        delx = [0,1,0,-1]
        dely = [-1,0,1,0]

        count = 0

        def dfs(i,j):
            grid[i][j] = '#'
            for k in range(4):
                newx = i+delx[k]
                newy = j+dely[k]
                if newx >= 0 and newx<m and newy >= 0 and newy < n:
                    newnode = grid[newx][newy]
                    if newnode == '1':
                        dfs(newx,newy)

        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    count += 1
                    dfs(i,j)
        
        return count