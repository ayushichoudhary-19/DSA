from collections import defaultdict
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = defaultdict(list)

        for course,preq in prerequisites:
            adj[preq].append(course)

        visited = set()
        path = set()
        

        def dfs(node):
            if node in path:
                return True
            
            if node in visited:
                return False


            visited.add(node)
            path.add(node)

            for nei in adj[node]:
                if dfs(nei):
                    return True
            
            path.remove(node)
            return False

        for course in range(numCourses):
            if course not in visited:
                if dfs(course):
                    return False
        

        return True