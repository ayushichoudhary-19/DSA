from collections import defaultdict
import heapq

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        heap = [(0,k)]
        dist = [float('inf')] * (n+1) #nodes are 1 indexed
        dist[k] = 0

        adjlist = defaultdict(list)

        for u,v,w in times:
            adjlist[u].append((v,w))

        while heap:

            curr_time, node = heapq.heappop(heap)

            if curr_time > dist[node]:
                continue

            for nei, weight in adjlist[node]:
                newtime = curr_time + weight

                if newtime < dist[nei]:
                    dist[nei] = newtime
                    heapq.heappush(heap,(newtime,nei))

        return -1 if max(dist[1:]) == float('inf') else max(dist[1:])