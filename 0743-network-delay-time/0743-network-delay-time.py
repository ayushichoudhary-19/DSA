from collections import defaultdict
import heapq

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        heap = [(0,k-1)]
        dist = [float('inf')] * (n) 
        dist[k-1] = 0 #nodes are 1 indexed so -1 in all nodes while storing in lists

        adjlist = defaultdict(list)

        for u,v,w in times:
            adjlist[u-1].append((v-1,w))

        while heap:

            curr_time, node = heapq.heappop(heap)

            if curr_time > dist[node]:
                continue

            for nei, weight in adjlist[node]:
                newtime = curr_time + weight

                if newtime < dist[nei]:
                    dist[nei] = newtime
                    heapq.heappush(heap,(newtime,nei))

        return -1 if max(dist) == float('inf') else max(dist)