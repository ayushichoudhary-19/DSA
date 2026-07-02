# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
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
        self.index = 0

    def next(self) -> int:
        node = self.order[self.index]
        self.index += 1
        return node

    def hasNext(self) -> bool:
        if self.index >= len(self.order):
            return False

        else:
            return True



# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()