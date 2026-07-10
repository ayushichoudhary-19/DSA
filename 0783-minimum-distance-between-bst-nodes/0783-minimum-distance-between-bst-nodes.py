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

    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        order = []
        order = self.inorder(root,order)
        n = len(order)
        mini = float('inf')
        for i in range(1,n):
            mini = min(mini,abs(order[i]-order[i-1]))
        return mini
