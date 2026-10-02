class Solution:
    def findTargetSumWays(self, nums: list[int], target: int) -> int:
        
        n = len(nums)
        INF = float('inf')

        total = sum(nums)

        # if max pos sum is 5, then if all val are negative we can have min -sum , so sum can go from -sum to positive sum. so total 2*sum + 1 possible values (+1 bec 0 sum is also possible)
        possible_currsum_values = 2*total + 1

        # now sum can be -5 but if we are representing it in index 0 to further then we need to map -5 to 0, -4 to 1 and so on, 
        # so mapping is that actual curr sum value is curr index of currsum - total sum. so if curr sum index in dp is 10, we know curr sum is 10-5 that is 5

        dp = [[0] * (possible_currsum_values) for _ in range(n+1)]

        # base case
        for currsum in range(possible_currsum_values):
            actual_currsum = currsum - total

            if actual_currsum == target:
                dp[n][currsum] = 1
            
            else:
                dp[n][currsum] = 0

        for idx in range(n-1,-1,-1):
            for currsum in range(possible_currsum_values-1,-1,-1):
                # take +nums[idx]
                if currsum + nums[idx] < possible_currsum_values:
                    dp[idx][currsum] += dp[idx + 1][currsum + nums[idx]]

                # take -nums[idx]
                if currsum - nums[idx] >= 0:
                    dp[idx][currsum] += dp[idx + 1][currsum - nums[idx]]

        return dp[0][total]

        #This is an important consequence of your offset.

        # Initially the actual sum is 0.

        # But its DP index is:

        # 0 + total = total