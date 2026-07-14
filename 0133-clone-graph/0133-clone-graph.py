"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None

        visited = {}

        def dfs(curr):
            if curr in visited:
                return visited[curr]

            newnode = Node(curr.val)

            visited[curr] = newnode

            for neighbor in curr.neighbors:
                newnode.neighbors.append(dfs(neighbor))

            return newnode
        
        return dfs(node)