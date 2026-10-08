from collections import deque

class Solution:
    def isBipartite(self, graph: list[list[int]]) -> bool:
        colors = {}
        total = len(graph)
        
        for u in range(total):
            if u in colors:
                continue
                
            q = deque([u])
            colors[u] = 'A'
            
            while q:
                node = q.popleft()
                
                for v in graph[node]:
                    if v not in colors:
                        colors[v] = 'B' if colors[node] == 'A' else 'A'
                        q.append(v)
                    else:
                        if colors[v] == colors[node]:
                            return False
                            
        return True
