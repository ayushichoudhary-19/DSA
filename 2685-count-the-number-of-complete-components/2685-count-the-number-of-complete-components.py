class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        visited = set()

        adj = collections.defaultdict(list)

        # prep the graph
        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)

        
        count = 0

        component = []

        def dfs(node):
            visited.add(node)
            component.append(node)
            for nei in adj[node]:
                if nei not in visited:
                    dfs(nei)

        for node in range(n):
            if node not in visited:

                component = []
                dfs(node)
            
                # now we have a new component, we check if it is a connected component
                totalNodesInComponent = len(component)
                
                # for it to be a complete component each node should have n-1  i.e.:  totalNodesInComponent-1 neighbours


                complete = True

                for u in component:
                    if len(adj[u]) != totalNodesInComponent-1:
                        complete = False
                        break
                    
                if complete:
                    count += 1

        return count