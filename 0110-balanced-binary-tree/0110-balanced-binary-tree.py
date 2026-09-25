# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: TreeNode | None) -> bool:

        def dfs(root):
            if root is None:
                return [True,0]

            l_balanced, l_height = dfs(root.left)
            r_balanced, r_height = dfs(root.right)

            is_balanced = l_balanced and r_balanced and abs(l_height-r_height) <= 1
            
            return [is_balanced , 1 + max(l_height,r_height)]

        return dfs(root)[0]