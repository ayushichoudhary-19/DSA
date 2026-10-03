class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        
        dp = [[-1] * len(word2) for _ in range(len(word1))]

        def dfs(i,j):
            if i == len(word1):
                return len(word2) - j
            
            if j == len(word2):
                return len(word1) - i
            
            if dp[i][j] != -1:
                return dp[i][j]

            matching = 0
            if word1[i] == word2[j]:
               return 0 + dfs(i+1,j+1)

            replace = 1 + dfs(i+1,j+1)
            deletion = 1 + dfs(i+1,j)
            insertion = 1 + dfs(i,j+1)

            dp[i][j]  = min(replace,deletion,insertion)
            return dp[i][j]

        return dfs(0,0)