class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:

        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1

        m = len(grid)
        n = len(grid[0])
        minheap = [(0,0,0)]

        distance = [[float('inf')] * n for _ in range(m)]
        distance[0][0] = 0

        delx = [-1,0,1,0]
        dely = [0,1,0,-1]

        while minheap:
            # currtime is actual time when we arrive at a cell
            currtime, row, col = heapq.heappop(minheap)

            if row == m-1 and col == n-1:
                return currtime

            if currtime > distance[row][col]:
                continue

            for k in range(4):
                newrow = row+delx[k]
                newcol = col+dely[k]

                if 0<=newrow<m and 0<=newcol<n:

                    nexttime = currtime+1

                    if grid[newrow][newcol] > currtime+1:
                        #for how long will we have to wait to be in this cell?
                        waittime = grid[newrow][newcol] - currtime

                        # now we need to do back and forth for this time, so 2 seconds for each ping-pong

                        # if wait time is 4 sec, we do 2 back n forths, so next time is +4, if it is 5 sec we need to do, 3 back n forths before we can reach it after 6 sec so next time is +6
                        
                        parity = 1 if waittime%2==0 else 0
                        nexttime = grid[newrow][newcol] + parity

                    if nexttime < distance[newrow][newcol]:
                        heapq.heappush(minheap,(nexttime, newrow, newcol))
                        distance[newrow][newcol] = nexttime

        return distance[m-1][n-1]