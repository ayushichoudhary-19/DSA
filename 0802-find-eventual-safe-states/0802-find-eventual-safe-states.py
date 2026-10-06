class Solution:
    def eventualSafeNodes(self, graph: list[list[int]]) -> list[int]:

        n = len(graph)

        ans = []
        q = deque()
        indegree = [0] * n

        graphrev = [[] for _ in range(n)]

        # reverse the graph
            

        for node in range(n):
            for neigh in graph[node]:
                graphrev[neigh].append(node)
                indegree[node] += 1

        for node in range(n):
            if indegree[node] == 0:
                q.append(node)

        while q:

            node = q.popleft()
            ans.append(node)

            for nei in graphrev[node]:
                indegree[nei] -= 1
                if indegree[nei] == 0:
                    q.append(nei)
        ans.sort()
        return ans
