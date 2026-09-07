from collections import defaultdict
class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        visited = set()
        adj = defaultdict(list)

        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)

        component = []
        count = 0

        def checkconnected(component):
            # a connected component is one in which every node is connected to every other node, so if there are n nodes, then each has n-1 neighbours
            size = len(component)
            for node in component:
                totalNeighbors = len(adj[node])
                if totalNeighbors != size - 1:
                    return False
            
            return True


        def dfs(node):
            visited.add(node)

            component.append(node)
            for neig in adj[node]:
                if neig not in visited:
                    dfs(neig)

        for node in range(n):
            if node not in visited:
                dfs(node)
                # here we are returned when one new component is done travering
                # we check if it is a connected component
                if checkconnected(component):
                    count += 1
                
                component = []

        return count