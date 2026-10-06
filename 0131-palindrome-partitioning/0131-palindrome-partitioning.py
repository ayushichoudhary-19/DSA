class Solution:
    def partition(self, s: str) -> list[list[str]]:
        
        n = len(s)
        ans = []

        def ispalindrome(i, j):
            if i >= j:
                return True

            if s[i] != s[j]:
                return False

            return ispalindrome(i + 1, j - 1)

        def dfs(l, curr):

            if l == n:
                ans.append(curr[:])
                return

            for r in range(l, n):

                if ispalindrome(l, r):

                    curr.append(s[l:r+1])

                    dfs(r + 1, curr)

                    curr.pop()

        dfs(0, [])

        return ans