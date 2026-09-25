# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    maxi = float('-inf')
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        maxi = 0

        def dfs(root):
            nonlocal maxi
            if root is None:
                return 0

            l = dfs(root.left)
            r = dfs(root.right)
            maxi = max( maxi , l + r)

            return 1 + max(l,r)

        dfs(root)
        return maxi