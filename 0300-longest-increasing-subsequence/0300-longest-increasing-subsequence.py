class Solution:
    def lengthOfLIS(self, nums: list[int]) -> int:

        n = len(nums)

        dp = [[0] * (n+1) for _ in range(n+1)]

        # as last taken index can be from -1 to n-1 so we have n+1 options but we do index shift by making +1, so that -1 is represented by 0 in dp and so on

        for i in range(n-1,-1,-1):
            for lasttakenidx in range(i-1,-2,-1):

            # take in subsequence
                take = 0

                if lasttakenidx == -1 or nums[lasttakenidx] < nums[i]:
                    take = 1 + dp[i+1][i+1]
                
                # don't take
                dont_take = 0 + dp[i+1][lasttakenidx+1]

                dp[i][lasttakenidx+1] = max(take,dont_take)

        return dp[0][0]