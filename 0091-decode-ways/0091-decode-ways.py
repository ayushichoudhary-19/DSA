class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        # if anywhere we find a single zero that we gotta pick, then impossible case
        # pick only curr 
            # move index by 1
        # pick two if number is <= 26
            # move index by 2

        dp = [0] * n

        if s[0] != '0':
            dp[0] = 1
        else:
            dp[0] = 0

        for pos in range(1,n):
            singledigit = s[pos]

            if singledigit != '0':
                dp[pos] += dp[pos-1]
    
            doubledigit = -1
            
            temp = s[pos-1] + s[pos]
            if 10 <= int(temp) <= 26:
                doubledigit = temp

            if doubledigit!=-1:
                if pos == 1:
                    dp[pos] += 1
                else:
                    dp[pos] += dp[pos-2]
            
        return dp[n-1]
                

