# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorder(self,root,order):
        if not root:
            return
        
        self.inorder(root.left,order)
        order.append(root.val)
        self.inorder(root.right,order)
        
        return order

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        order = []
        order = self.inorder(root,order)
        return order[k-1]