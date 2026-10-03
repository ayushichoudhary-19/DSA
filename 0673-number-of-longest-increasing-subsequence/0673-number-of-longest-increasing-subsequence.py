class Solution:
    def findNumberOfLIS(self, nums: list[int]) -> int:

        n = len(nums)

        dp = [1] * n
        count = [1] * n

        for i in range(n):
            for j in range(i):

                if nums[j] < nums[i]:

                    if dp[j] + 1 > dp[i]:
                        dp[i] = dp[j] + 1
                        count[i] = count[j]

                    elif dp[j] + 1 == dp[i]:
                        count[i] += count[j]

        maxlen = max(dp)

        ans = 0
        for i in range(n):
            if dp[i] == maxlen:
                ans += count[i]

        return ans