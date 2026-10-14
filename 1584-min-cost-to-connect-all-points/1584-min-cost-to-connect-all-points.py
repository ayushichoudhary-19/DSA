class Solution:
    def minCostConnectPoints(self, points: list[list[int]]) -> int:
        
        # using prims algo
        n = len(points)
        added = set()

        mt_cost = 0

        if n == 1:
            return 0

           # cost, points_index
        q = [(0,0)]

        while q and len(added)!=n:
            cost, nodeidx = heapq.heappop(q)
            
            if nodeidx in added:
                continue

            added.add(nodeidx)
            
            mt_cost += cost

            # Dynamically find neighbors without an adjacency list
            x1, y1 = points[nodeidx]
            for v in range(n):
                if v not in added:
                    cost = abs(x1 - points[v][0]) + abs(y1 - points[v][1])
                    heapq.heappush(q, (cost, v))
        
        return mt_cost