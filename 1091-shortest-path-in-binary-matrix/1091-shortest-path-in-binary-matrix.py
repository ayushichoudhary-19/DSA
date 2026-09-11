class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:

        if grid[0][0] == 1:
            return -1
        q = deque()
        n = len(grid)
        q.append((1,0,0))

        visited = set()
        visited.add((0,0))

        delx = [1,1,0,-1,-1,-1,0,1]
        dely = [0,1,1,1,0,-1,-1,-1]

        while q:
            total,row,col = q.popleft()

            if row == n-1 and col == n-1:
                return total
            
            for k in range(8):
                newrow = row + delx[k]
                newcol = col + dely[k]

                if 0 <= newrow < n and 0 <= newcol < n and grid[newrow][newcol] == 0 and (newrow, newcol) not in visited:
                    visited.add((newrow,newcol))
                    q.append((total+1,newrow,newcol))

            
        return -1