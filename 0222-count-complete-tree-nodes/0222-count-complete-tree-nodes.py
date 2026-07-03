# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def leftH(self,root):
        if not root:
            return 0

        return 1 + self.leftH(root.left)

    def rightH(self,root):
        if not root:
            return 0

        return 1 + self.rightH(root.right)

    def countNodes(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        lh = self.leftH(root)
        rh = self.rightH(root)

        if lh == rh:
            return 2**lh - 1
        else:
            
            return 1 +  self.countNodes(root.left) + self.countNodes(root.right)
        