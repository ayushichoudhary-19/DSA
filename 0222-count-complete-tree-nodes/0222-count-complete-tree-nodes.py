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
            return (1 << lh) - 1

            #1 << h shifts the binary 1 left by h positions, and since each left shift multiplies by 2, 1 << h = 2^h.
        else:
            
            return 1 +  self.countNodes(root.left) + self.countNodes(root.right)
        