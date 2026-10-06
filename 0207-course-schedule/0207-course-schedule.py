class Solution:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:
        
        visited = set()

        adj = defaultdict(list)

        indegree = [0]*numCourses

        for v, u in prerequisites:
            adj[u].append(v)
            indegree[v] += 1
        
        q = deque()

        for node in range(numCourses):
            if indegree[node] == 0:
                q.append(node)

        while q:
            node = q.popleft()

            for nei in adj[node]:
                indegree[nei] -= 1

                if indegree[nei] == 0:
                    q.append(nei)
                    
        return sum(indegree) == 0


            



            

        