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
        
        if self.prev is not None:
            self.mini = min(self.mini, root.val - self.prev)
        
        self.prev = root.val
    
        self.inorder(root.right)

    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        self.prev = None
        self.mini = float('inf')
        self.inorder(root)

        return self.mini
