class Solution:
    def maxPathSum(self, root: TreeNode | None) -> int:
        maxi = float('-inf')

        def dfs(root):
            nonlocal maxi

            if root is None:
                return 0

            l = max(0, dfs(root.left))
            r = max(0, dfs(root.right))

            # Path that uses both sides through this node
            maxi = max(maxi, root.val + l + r)

            # Path that can be extended by the parent
            return root.val + max(l, r)

        dfs(root)
        return maxi