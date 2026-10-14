class Solution:
    def networkDelayTime(self, times: list[list[int]], n: int, k: int) -> int:


        distance = [float('inf')] * (n+1)

        adj = defaultdict(list)

        for u,v,w in times:
            adj[u].append((v,w))

        q = [(0,k)]
        distance[k] = 0

        while q:

            currwt, node = heapq.heappop(q)

            if currwt > distance[node]:
                continue

            for nei,w in adj[node]:
                if distance[nei] > currwt + w:
                    distance[nei] = currwt+w
                    heapq.heappush(q,(currwt+w,nei))

        
        ans = max(distance[1:])
        return ans if ans < float('inf') else -1
