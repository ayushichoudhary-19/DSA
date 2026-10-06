class Solution:
    def findOrder(self, numCourses: int, prerequisites: list[list[int]]) -> list[int]:
        
        adj = defaultdict(list)

        indegree = [0]*numCourses

        for v,u in prerequisites:
            adj[u].append(v)
            indegree[v] += 1
        
        visited = set()
        q = deque()

        for node in range(numCourses):
            if indegree[node]==0:
                q.append(node)


        ans = []

        while q:
            
            node = q.popleft()
            ans.append(node)
            visited.add(node)

            for nei in adj[node]:
                if nei not in visited:
                    indegree[nei] -=1
                    if indegree[nei] == 0:
                        q.append(nei)
            

        return [] if sum(indegree)!=0 else ans