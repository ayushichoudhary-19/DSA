class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[0] * 301 for _ in range(301)]

        maxsofar = 0
        for i in range(n):
            currval = nums[i]
            maxsub = 1

            for diff in range(300,-1,-1):
                number1 = currval + diff
                number2 = currval - diff

                if number1 <= 300 and dp[number1][diff]:
                    maxsub = max(maxsub , 1 + dp[number1][diff])
                
                if number2 >= 0 and dp[number2][diff]:
                    maxsub = max(maxsub, 1 + dp[number2][diff])

                dp[currval][diff] = maxsub
                maxsofar = max(maxsofar,maxsub)

        
        return maxsofar