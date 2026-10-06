class Solution:
    def allPathsSourceTarget(self, graph: list[list[int]]) -> list[list[int]]:
    
        n = len(graph)
        path = []
        ans = []

        def dfs(node):

            path.append(node)

            for nei in graph[node]:
                dfs(nei)
            
            if node == n - 1:
                ans.append(path[:])

            path.pop()

        dfs(0)
        return ans