from collections import defaultdict, deque

class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            # single node
            return [0]
        q = deque()
        visited = {}
        degrees = [0]*n

        adj = defaultdict(list)


        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)
            degrees[u] += 1
            degrees[v] += 1

        for node in range(n):
            if degrees[node] == 1:
                # this is a leaf node
                q.append(node)

        remainingInTree = n
        centres = []

        while remainingInTree > 2:
            # You must remove all leaf nodes of current layer together before checking the next layer, else you'll start processing newly-created leaves in the same round, which is incorrect.
            currentLayerLeafNodes = len(q)
            remainingInTree -= currentLayerLeafNodes

            # remove nodes with indegree 1 i.e. leaf nodes from graph
   
            # popping only current layer leaf nodes at a time from q
            for _ in range(currentLayerLeafNodes):
                node = q.popleft()
                degrees[node] = 0
                for nei in adj[node]:
                    degrees[nei] -= 1
                    if degrees[nei] == 1:
                        q.append(nei)

        
        while q:
            node = q.popleft()
            centres.append(node)
        
        return centres
