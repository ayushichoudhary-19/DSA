class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        # colors = {}
        # total = len(graph)
        
        # for u in range(total):
        #     if u not in colors:
        #         colors[u] = 'A'
        #     for v in graph[u]:
        #         if v not in colors:
        #             if colors[u] == 'A':
        #                 colors[v] = 'B'
        #             else:
        #                 colors[v] = 'A'
        #         else:
        #             if colors[v] == colors[u]:
        #                 return False

        # return True

              
            
        colors = {}
        total = len(graph)
  
        def dfs(node):
            for v in graph[node]:
                if v not in colors:
                    if colors[node] == 'A':
                        colors[v] = 'B'
                    else:
                        colors[v] = 'A'

                    if not dfs(v):
                        return False

                else:
                    if colors[v] == colors[node]:
                        return False

            return True
            

        for u in range(total):
            if u not in colors:
                colors[u] = 'A'
                if not dfs(u):
                    return False
        

        return True