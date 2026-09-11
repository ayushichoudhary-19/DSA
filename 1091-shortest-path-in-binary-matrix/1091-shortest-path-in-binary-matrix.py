class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:

        if grid[0][0] == 1:
            return -1
        heap = [(1,0,0)]
        n = len(grid)

        dist = [[float('inf')]* n for _ in range(n)]

        dist[0][0] = 1

        delx = [1,1,0,-1,-1,-1,0,1]
        dely = [0,1,1,1,0,-1,-1,-1]

        while heap:
            currminlen, row, col = heapq.heappop(heap)

            if currminlen > dist[row][col]:
                continue

            if row == n-1 and col == n-1:
                return currminlen
            
            for k in range(8):
                newrow = row + delx[k]
                newcol = col + dely[k]

                if 0 <= newrow < n and 0 <= newcol < n and grid[newrow][newcol] == 0:
                    newlen = currminlen + 1

                    if newlen < dist[newrow][newcol]:
                        dist[newrow][newcol] = newlen
                        heapq.heappush(heap,(newlen,newrow,newcol))

            
        return -1


