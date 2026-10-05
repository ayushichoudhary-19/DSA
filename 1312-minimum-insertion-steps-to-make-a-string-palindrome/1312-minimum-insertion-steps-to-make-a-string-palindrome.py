class Solution:
    def minInsertions(self, s: str) -> int:
        

        n = len(s)

        dp = [[-1] * n for _ in range(n)]

        def dfs(l,r):

            if l >= r:
                return 0

            if dp[l][r] != -1:
                return dp[l][r]
            
        
            take = 0
            if s[l]==s[r]:
                take = 0 + dfs(l+1,r-1)
            
            else:
                take = min(1 + dfs(l,r-1), 1 + dfs(l+1, r))

            dp[l][r] = take
            return take

        return dfs(0,n-1)
            

