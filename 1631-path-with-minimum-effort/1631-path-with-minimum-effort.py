class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        # destination given
        # weights are node val difference
        # sourse given
        # have to find min weight if path is possible
        # using djikstra's algo

        heap = [(0,0,0)] # heap stores abs diff and node position

        m = len(heights)
        n = len(heights[0])
        delx = [0,1,0,-1]
        dely = [-1,0,1,0]

        dist = [[float('inf')] * n for _ in range(m)]
        dist[0][0] = 0

        while heap:
            curr_abs_diff, row, col = heapq.heappop(heap)
            
            if curr_abs_diff > dist[row][col]:
                continue

            for k in range(4):
                new_row = row + delx[k]
                new_col = col + dely[k]

                if 0 <= new_row < m and 0 <= new_col < n:
                    edge_diff = abs(heights[row][col] - heights[new_row][new_col])

                    new_abs_diff = max(curr_abs_diff, edge_diff)

                    if new_abs_diff < dist[new_row][new_col]:
                        dist[new_row][new_col] = new_abs_diff
                        heapq.heappush(heap,(new_abs_diff,new_row,new_col))
                

        return dist[m-1][n-1]




        