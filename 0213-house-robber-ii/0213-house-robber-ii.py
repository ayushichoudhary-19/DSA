class Solution:

    def solve(self, nums):
        n = len(nums)
        if n == 1:
            return nums[0]
        dp = [0] * n
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])

        for i in range(2, n):
            dp[i] = max(
                dp[i - 1],
                dp[i - 2] + nums[i]
            )

        return dp[n - 1]

    def rob(self, nums: list[int]) -> int:
        n = len(nums)

        if n == 1:
            return nums[0]

        return max(
            self.solve(nums[:n - 1]),
            self.solve(nums[1:])
        )