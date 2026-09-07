from collections import defaultdict, deque
class Solution:

    def snakesAndLadders(self, board: List[List[int]]) -> int:

        q = deque()
        visited = set()
        n = len(board)

        q.append(1)
        countLevels = 0

        while q:
            size = len(q)

            # capture the size of the current level, process only those nodes, then increment countLevels once
            for _ in range(size):
                node = q.popleft()

                if node in visited:
                    continue

                visited.add(node)

                for i in range(1, 7):
                    nextnode = min(node + i, n * n)

                    # Convert square number to 0-indexed
                    x = nextnode - 1

                    # Find row from bottom
                    row_from_bottom = x // n

                    # Find column within that row
                    col = x % n

                    # Convert row-from-bottom to matrix row
                    row = n - 1 - row_from_bottom

                    # Every other row is reversed
                    if row_from_bottom % 2 == 1:
                        col = n - 1 - col

                    # Apply snake / ladder
                    if board[row][col] != -1:
                        nextnode = board[row][col]

                    # If we reached the final square, return number of dice rolls
                    if nextnode == n * n:
                        return countLevels + 1

                    if nextnode not in visited:
                        q.append(nextnode)

            countLevels += 1

        return -1