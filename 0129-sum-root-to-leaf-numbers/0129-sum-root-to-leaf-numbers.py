# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def sumNumbers(self, root: TreeNode | None) -> int:

        total = 0
        curr = 0
        def dfs(node,parent):
            nonlocal total
            if node is None:
                return 0


            curr = parent * 10 + node.val

            if node.left is None and node.right is None:
                total = total + curr
                
            if node.left:
                dfs(node.left,curr)

            if node.right:
                dfs(node.right,curr)
            
        
        dfs(root,0)
        return total