class Solution:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:
        
        visited = set()
        path = set()

        adj = defaultdict(list)
        for u, v in prerequisites:
            adj[u].append(v)

        def dfs(node):

            visited.add(node)
            path.add(node)

            for neigh in adj[node]:

                if neigh not in visited:
                    if not dfs(neigh):
                        return False
                    
                if neigh in path:
                    return False
            
            path.remove(node)
            return True

        for node in range(numCourses):
            if node not in visited:
                if not dfs(node):
                    return False
        
        return True