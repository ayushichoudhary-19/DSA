class Solution:
    def bestTeamScore(self, scores: list[int], ages: list[int]) -> int:
        
        n = len(scores)

        dp = [0]*(n+1)
        # in dp, the last chosen index j can be from -1 to n-1 so i have to make it shift index from 0 to n, so i do +1 in dp array (not in score/age)
        

        # Sort because input order is arbitrary; otherwise DFS must preserve it.
        # For example, if we pick player 7, we can't pick player 2 afterward, even though
        # input order doesn't matter. Sorting by age lets us consider players from younger
        # to older and find the best valid combination of scores.

        players = list(zip(ages,scores))
        players.sort()
        ages = [age for age,score in players]
        scores = [score for age,score in players]

        for i in range(n-1, -1, -1):
            for j in range(i-1, -2, -1):

                take = 0

                if j == -1 or scores[i] >= scores[j]:
                    take = scores[i] + dp[i+1]

                dont_take = dp[j+1]

                dp[j+1] = max(dont_take, take)

        return max(dp)