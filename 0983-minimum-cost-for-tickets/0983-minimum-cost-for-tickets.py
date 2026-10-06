class Solution:
    def mincostTickets(self, days: list[int], costs: list[int]) -> int:
        
        n = len(days)
        dp = [-1] * n

        def dfs(i):

            if i == n:
                return 0

            if dp[i] != -1:
                return dp[i]
            
            onedaypass, sevendaypass, thirtydaypass = 0, 0, 0

            # find first element > till and that is your new day
            # for which you need to buy a ticket

            found = False
            for j in range(i, n):
                if days[j] > days[i]:
                    onedaypass = costs[0] + dfs(j)
                    found = True
                    break


            if not found:
                onedaypass = costs[0] + dfs(n)
            
            found = False
            for j in range(i, n):
                if days[j] > days[i] + 6:
                    sevendaypass = costs[1] + dfs(j)
                    found = True
                    break

            if not found:
                sevendaypass = costs[1] + dfs(n)

            found = False
            for j in range(i, n):
                if days[j] > days[i] + 29:
                    thirtydaypass = costs[2] + dfs(j)
                    found = True
                    break

            if not found:
                thirtydaypass = costs[2] + dfs(n)

            dp[i] = min(onedaypass, sevendaypass, thirtydaypass)
            return dp[i]

        return dfs(0)