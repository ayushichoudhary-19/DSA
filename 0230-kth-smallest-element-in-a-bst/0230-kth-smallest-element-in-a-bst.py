# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self,root,k):

        if not root:
            return

        self.helper(root.left, k)
            
        self.count += 1
        
        if self.count == k:
            self.ans = root.val
            return

        self.helper(root.right,k)

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.count = 0
        self.ans = 0
        self.helper(root,k)
        return self.ans