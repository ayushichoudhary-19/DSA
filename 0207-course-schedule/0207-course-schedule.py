from collections import defaultdict

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = defaultdict(list)

        for u, v in prerequisites:
            adj[u].append(v)

        visited = set()
        path = set()

        def dfs(node):
            if node in path:
                return True      # cycle found

            if node in visited:
                return False     # already processed

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
                    return False   # cannot finish

        return True