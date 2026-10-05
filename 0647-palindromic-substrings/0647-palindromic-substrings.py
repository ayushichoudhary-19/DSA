class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)

        dp = [[-1]*n for _ in range(n)]

        def ispalindrome(l, r):
            if l >= r:
                return 1

            if dp[l][r] != -1:
                return dp[l][r]

            if s[l] != s[r]:
                return 0

            dp[l][r] = ispalindrome(l+1,r-1)
            return dp[l][r]

        count = 0

        for l in range(n):
            for r in range(n-1,l-1,-1):

                if ispalindrome(l,r):
                    count +=1

        return count