from collections import defaultdict
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = defaultdict(list)
        
        for course, prereq in prerequisites:
            adj[prereq].append(course)

        ans = []
        visited = set()
        path = set()

        def dfs(node):
            if node in path:
                # cycle found
                return True
            if node in visited:
                # already visited
                return False
            
            visited.add(node)
            path.add(node)

            for nei in adj[node]:
                if dfs(nei):
                    return True
            
            path.remove(node)
            ans.append(node)

            return False

        for course in range(numCourses):
                if dfs(course):
                    #if dfs gives a cycle return []
                    return []
        
        return ans[::-1]
