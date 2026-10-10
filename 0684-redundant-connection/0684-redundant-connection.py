class DSU:
    def __init__(self,n):
        self.parent = list(range(n))
        self.size = [1]*n

    def find(self,x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        
        return self.parent[x]

    def union(self,a,b):
        rootA = self.find(a)
        rootB = self.find(b)

        if rootA == rootB:
            return False # already in same grp
        
        if self.size[rootA] < self.size[rootB]:
            rootA,rootB = rootB,rootA
        
        self.parent[rootB] = rootA
        self.size[rootA] += self.size[rootB]

        return True


class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)

        dsu = DSU(n+1)

        for u, v in edges:
            if not dsu.union(u,v):
                #since union of already in same grp return false, we checked false case for when they are already connected
                return [u,v]

        return []