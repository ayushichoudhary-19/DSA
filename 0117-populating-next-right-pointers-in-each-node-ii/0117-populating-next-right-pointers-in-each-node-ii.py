"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

from collections import deque

class Solution:

    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []

        q = deque([root])
        ans = []

        while q:
            n = len(q)
            level = []

            for _ in range(n):
                node = q.popleft()
                level.append(node)

                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)

            ans.append(level)

        return ans

    def connect(self, root: 'Node') -> 'Node':
        
        levels = self.levelOrder(root)

        for level in levels:
            for i in range(len(level)-1):
                level[i].next = level[i+1]
            
            level[-1].next = None
                
        return root