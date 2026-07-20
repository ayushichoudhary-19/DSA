class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        ans = []

        adj = collections.defaultdict(list)

        for u,v in prerequisites:
            adj[u].append(v)

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
                    #cycle is there
                    return True

            path.remove(node)
            ans.append(node)
            return False

        for course in range(numCourses):
            if course not in visited:
                if dfs(course):
                    #cycle exists
                    return []
        
        return ans
            
        