class Solution:
    def wordBreak(self, s: str, wordDict: list[str]) -> bool:

        dp = [-1] * (len(s) + 1)

        def dfs(i):

            if i == len(s):
                dp[i] = True
                return True

            if dp[i] != -1:
                return dp[i]

            for j in range(i, len(s)):
                word = s[i:j+1]

                if word in wordDict:
                    if dfs(j + 1):
                        dp[i] = True
                        return True

            # We tried every possible word starting at i
            # and none could lead to a valid segmentation.
            dp[i] = False
            return dp[i]

        return dfs(0)