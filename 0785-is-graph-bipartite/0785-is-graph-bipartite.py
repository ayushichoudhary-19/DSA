class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        colors = {}
        total = len(graph)

        def dfs(node):
            for nei in graph[node]:
                if nei not in colors:
                    if colors[node] == 'A':
                        colors[nei] = 'B'
                    else:
                        colors[nei] = 'A'
                    
                    if not dfs(nei):
                        return False
                
                elif colors[nei] == colors[node]:
                    return False

            return True
         
        for node in range(total):
            if node not in colors:
                colors[node] = 'A'
                if not dfs(node):
                    return False

        return True