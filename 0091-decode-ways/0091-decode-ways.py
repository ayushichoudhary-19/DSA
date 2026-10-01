class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        # if anywhere we find a single zero that we gotta pick, then impossible case

        # pick only curr 
            # move index by 1
        # pick two if number is <= 26
            # move index by 2

        dp = [-1]*n

        def dfs(pos):
            if pos == n:
                return 1

            if dp[pos] != -1:
                return dp[pos]

            singledigit = s[pos]

            if singledigit == '0':
                return 0

            doubledigit = -1

            if pos < n-1:
                temp = s[pos] + s[pos+1]
                if int(temp) <= 26:
                    doubledigit = temp

            

            ans = dfs(pos+1)
            if doubledigit!=-1 and pos + 2 <= n:
                ans += dfs(pos+2)
            
            dp[pos] = ans
            return dp[pos]

        return dfs(0)
                

