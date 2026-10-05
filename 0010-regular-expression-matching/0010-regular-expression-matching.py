class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m = len(s)
        n = len(p)

        dp = [[-1]*(n+1) for _ in range(m+1)]
        def dfs(i, j):

            if j == n:
                return i == m

            if dp[i][j] != -1:
                return dp[i][j]
            
            # Case: next pattern character is *
            if j + 1 < n and p[j + 1] == '*':
                
                # Option 1: use * zero times
                if dfs(i, j + 2):
                    dp[i][j] = True
                    return dp[i][j]

                # Option 2: use * one or more times
                if i < m and (s[i] == p[j] or p[j] == '.'):
                    dp[i][j] = dfs(i + 1, j)
                    return dp[i][j]
                
                dp[i][j] = False
                return dp[i][j]

            # Normal character / .
            if i < m and (s[i] == p[j] or p[j] == '.'):
                dp[i][j] = dfs(i + 1, j + 1)
                return dp[i][j]

            dp[i][j] = False
            return dp[i][j]

        return dfs(0, 0)