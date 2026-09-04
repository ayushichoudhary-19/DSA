from collections import defaultdict, deque
# For a directed graph, cycle detection with BFS is done using indegree.

# Idea
# Count how many incoming edges each node has.
# Put all nodes with indegree 0 into a queue.
# Remove them one by one.
# Every time you remove a node, decrease the indegree of its neighbors.
# If a neighbor becomes 0, push it into the queue.
# Count how many nodes you processed.
# If you processed all nodes, there is no cycle.
# If some nodes remain, they are part of a cycle.


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:

        adjlist = defaultdict(list)
        indegree = [0] * numCourses

        for course, prerequisite in prerequisites:
            adjlist[prerequisite].append(course)
            indegree[course] += 1

        q = deque()

        for course in range(numCourses):
            if indegree[course] == 0:
                q.append(course)

        completed = 0

        while q:
            node = q.popleft()
            for neig in adjlist[node]:
                indegree[neig] -= 1

                if indegree[neig] == 0:
                    q.append(neig)

            completed += 1

        return completed == numCourses