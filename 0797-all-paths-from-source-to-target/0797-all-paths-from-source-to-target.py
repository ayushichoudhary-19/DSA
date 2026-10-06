class Solution:
    def allPathsSourceTarget(self, graph: list[list[int]]) -> list[list[int]]:
    
        n = len(graph)
        path = [] #use list bec set can't preserve order
             
        ans = []

        def dfs(node):

            if node in path:
                return
            
            path.append(node)

            for nei in graph[node]:
                if nei not in path:
                    dfs(nei)
            
            if node == n-1:
                ans.append(path[:])

            path.pop()

            return 

        dfs(0)
        return ans