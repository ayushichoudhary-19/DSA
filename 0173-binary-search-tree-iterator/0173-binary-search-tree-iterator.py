# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque

class BSTIterator:
    def inorder(self,root,order):
        if not root:
            return

        self.inorder(root.left,order)
        order.append(root.val)
        self.inorder(root.right,order)

        return order

    def __init__(self, root: Optional[TreeNode]):
        self.order = self.inorder(root,[])
        self.q = deque(self.order)

    def next(self) -> int:
        node = self.q.popleft()
        return node

    def hasNext(self) -> bool:
        return len(self.q) != 0



# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()