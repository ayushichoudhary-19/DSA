# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self,root, totalSum,branchNum):
        if not root:
            return 0

        branchNum = branchNum * 10 + root.val

        if not root.left and not root.right:
            return branchNum
        
        return self.helper(root.left,totalSum,branchNum) + self.helper(root.right,totalSum,branchNum)

    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        return self.helper(root,0,0)