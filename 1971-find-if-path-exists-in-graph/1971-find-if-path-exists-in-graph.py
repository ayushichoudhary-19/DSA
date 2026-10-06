from collections import defaultdict, deque

class Solution:
    def validPath(self, n: int, edges: list[list[int]], source: int, destination: int) -> bool:
        
        adj = defaultdict(list)

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        visited = [0] * n

        q = deque()
        q.append(source)
        visited[source] = 1

        while q:
            node = q.popleft()

            if node == destination:
                return True

            for neigh in adj[node]:
                if not visited[neigh]:
                    visited[neigh] = 1
                    q.append(neigh)
            
        return False