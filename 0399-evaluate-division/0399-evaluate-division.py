class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        
        adj = defaultdict(list)
        n = len(equations)
    
        for i in range(n):
            adj[equations[i][0]].append([equations[i][1],values[i]])
            if values[i] != 0.0:
                adj[equations[i][1]].append([equations[i][0],1/values[i]])

        def pathProd(source,destination):
            visited = {}
            q = deque()
            q.append((source,1))
            visited[source] = 1

            while q:
                node,prod = q.popleft()

                if node == destination:
                    return prod

                for neigh,val in adj[node]:
                    if neigh not in visited:
                        visited[neigh] = 1
                        q.append((neigh,prod*val))
                
            return -1
        
        ans = []
        for s,d in queries:
            if s not in adj or d not in adj:
                ans.append(-1/1)
            elif s==d:
                ans.append(1/1)
            else:
                ans.append(pathProd(s,d))
        
        return ans