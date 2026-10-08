from collections import deque

class Solution:
    def isPrintable(self, targetGrid: list[list[int]]) -> bool:
        m = len(targetGrid)
        n = len(targetGrid[0])

        rect = {}

        # 1. find bounding rectangle of every color
        for r in range(m):
            for c in range(n):
                color = targetGrid[r][c]

                if color not in rect:
                    rect[color] = [r, c, r, c]
                else:
                    rect[color][0] = min(rect[color][0], r)
                    rect[color][1] = min(rect[color][1], c)
                    rect[color][2] = max(rect[color][2], r)
                    rect[color][3] = max(rect[color][3], c)

        colors = set(rect.keys())

        # dependency graph
        graph = {color: set() for color in colors}
        indegree = {color: 0 for color in colors}

        # 2. build dependencies
        for color in colors:
            r1, c1, r2, c2 = rect[color]

            for r in range(r1, r2 + 1):
                for c in range(c1, c2 + 1):

                    other = targetGrid[r][c]

                    if other != color and other not in graph[color]:
                        # color must be printed before other
                        graph[color].add(other)
                        indegree[other] += 1

        # 3. Kahn's algorithm
        q = deque()

        for color in colors:
            if indegree[color] == 0:
                q.append(color)

        processed = 0

        while q:
            color = q.popleft()
            processed += 1

            for nei in graph[color]:
                indegree[nei] -= 1

                if indegree[nei] == 0:
                    q.append(nei)

        # If every color can be processed, dependency graph is acyclic
        return processed == len(colors)