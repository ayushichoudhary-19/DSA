class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: list[list[int]]) -> list[int]:
        
        visited = set()

        adj = defaultdict(list)

        inorder = [0]*n
        for u,v in edges:
            adj[u].append(v)
            inorder[v] += 1

        ans=[]

        for i in range(n):
            if inorder[i] == 0:
                ans.append(i)

        return ans
            
