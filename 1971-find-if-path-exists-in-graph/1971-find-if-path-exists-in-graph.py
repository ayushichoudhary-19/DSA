from collections import defaultdict

class Solution:
    def validPath(self, n: int, edges: list[list[int]], source: int, destination: int) -> bool:
        

        adj = defaultdict(list)
        # or adj = [[] for _ in range(n)]   
        

        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)

        visited = [0]*n

        def dfs(node):

            if node == destination:
                return True

            visited[node] = 1

            for neigh in adj[node]:
                if not visited[neigh]:
                   if dfs(neigh):
                    return True

            return False

        return dfs(source)
