class Solution:
    def shortestPathBinaryMatrix(self, grid: list[list[int]]) -> int:
        
        n = len(grid)

        if grid[0][0] == 1 or grid[n-1][n-1] == 1: return -1

        q = deque()

        q.append((1,0,0))
        grid[0][0] = 1

        delx = [-1,-1,-1,0,1,1,1,0]
        dely = [-1,0,1,1,1,0,-1,-1]

        while q:

            currlen,row,col = q.popleft()


            for i in range(8):
                newrow = row + delx[i]
                newcol = col + dely[i]

                if row == n-1 and col == n-1:
                    return currlen

                if 0<=newrow<n and 0<=newcol<n and grid[newrow][newcol] == 0:
                    grid[newrow][newcol] = 1 
                    q.append((currlen+1,newrow,newcol))

        return -1
                

        