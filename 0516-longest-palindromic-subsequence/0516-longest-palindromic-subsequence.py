class Solution:

    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)

        dp = [[-1] * n for _ in range(n)]

        def dfs(l,r):

            if l > r:
                return 0

            
            if l == r:
                return 1

            if dp[l][r] != -1:
                return dp[l][r]

            gain = 0
            # take if adding this makes it a palindrome then only count, else take but dont count as a palindrome seq
            if s[l] == s[r]:
                gain = 2 + dfs(l+1,r-1)
            else:
                gain = 0 + max(dfs(l+1,r), dfs(l,r-1))

            dp[l][r] = gain
            return dp[l][r]

        return dfs(0,n-1)