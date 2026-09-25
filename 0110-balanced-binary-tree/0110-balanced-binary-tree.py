class Solution:
    def isBalanced(self, root: TreeNode | None) -> bool:

        def dfs(root):
            if root is None:
                return True, 0

            l_balanced, l_height = dfs(root.left)

            if not l_balanced:
                return False, 0

            r_balanced, r_height = dfs(root.right)

            if not r_balanced:
                return False, 0

            if abs(l_height - r_height) > 1:
                return False, 0

            return True, 1 + max(l_height, r_height)

        return dfs(root)[0]