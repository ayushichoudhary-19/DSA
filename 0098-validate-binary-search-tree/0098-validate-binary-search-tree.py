# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorder(self,root):
        if not root:
            return
        
        self.inorder(root.left)
        self.order.append(root.val)
        self.inorder(root.right)

    
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        self.order = []
        self.inorder(root)
        
        n = len(self.order)
        for i in range(1,n):
            if self.order[i] <= self.order[i-1]:
                return False

        return True