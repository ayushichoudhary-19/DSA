class Solution:
    def getAncestors(self, n: int, edges: list[list[int]]) -> list[list[int]]:
        
        ans = [[] for _ in range(n)]

        adj = defaultdict(list)

        dp = [None] * n

        # a reversed graph
        for u,v in edges:
            adj[v].append(u)

        def dfs(node):

            if dp[node] != None:
                return dp[node]
            
            ancestors = set()
            
            for nei in adj[node]:
                ancestors.add(nei)

                ancestors.update(dfs(nei))

            dp[node] = ancestors
            return dp[node]

    
        for i in range(n):
            ans[i] = list(dfs(i))       

        for each in ans:
            each.sort()
            
        return ans