class Solution:
    def kthSmallest(self, root: TreeNode | None, k: int) -> int:
        cnt = 0

        def dfs(root):
            nonlocal cnt

            if not root:
                return None

            # Left
            result = dfs(root.left)
            if result is not None:
                return result

            # Current
            cnt += 1
            if cnt == k:
                return root.val

            # Right
            return dfs(root.right)

        return dfs(root)