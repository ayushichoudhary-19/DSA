# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self,root):
        if not root:
            return

        self.helper(root.left)

        if self.prev is not None and self.prev >= root.val:
            self.ans = False
            return 

        self.prev = root.val

        self.helper(root.right)

    
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        self.prev = None
        self.ans = True
        self.helper(root)
        

        return self.ans