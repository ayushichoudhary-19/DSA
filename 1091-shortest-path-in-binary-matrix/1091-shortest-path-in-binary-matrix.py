class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:

        n = len(grid)
        if grid[0][0] == 1 or grid[n-1][n-1] == 1:
            return -1
        q = deque()
        q.append((1,0,0))

        # changing grid to mark visited - not interview recommended but ask if u can
        grid[0][0] = 1

        delx = [1,1,0,-1,-1,-1,0,1]
        dely = [0,1,1,1,0,-1,-1,-1]

        while q:
            total,row,col = q.popleft()

            if row == n-1 and col == n-1:
                return total
            
            for k in range(8):
                newrow = row + delx[k]
                newcol = col + dely[k]

                if 0 <= newrow < n and 0 <= newcol < n and grid[newrow][newcol] == 0:
                    grid[newrow][newcol] = 1
                    q.append((total+1,newrow,newcol))

            
        return -1