# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: TreeNode | None) -> int:
        maxdepth = 0

        currdepth = 0

        def dfs(node, currdepth):
            nonlocal maxdepth
            if node is None:
                maxdepth = max(maxdepth,currdepth)
                return

            dfs(node.left,currdepth+1)
            dfs(node.right,currdepth+1)

        dfs(root,currdepth)

        return maxdepth