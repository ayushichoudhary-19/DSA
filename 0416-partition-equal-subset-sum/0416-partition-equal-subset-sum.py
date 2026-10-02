class Solution:
    def canPartition(self, nums: list[int]) -> bool:
        
        n = len(nums)

        # if total sum, then dividing in 2 subsets of equal sum means each subset has sum total/2
        # so we need ot find a subset in array that sums up to total/2
        total = sum(nums)

        if total%2 != 0: return False #odd sum can not be divided into two equal sums

        target = int(total/2)

        dp = [[-1]*(target+1) for _ in range(n+1)]

        def dfs(idx,currsum):

            if currsum > target:
                return False

            if currsum == target:
                return True
            
            # we can reach the target at final element too so we do that check before below check
            if idx == n:
                return False

            if dp[idx][currsum] != -1:
                return dp[idx][currsum]

                                         # take                  #dont take
            dp[idx][currsum] = dfs(idx+1,currsum+nums[idx]) or dfs(idx+1,currsum)
            return dp[idx][currsum]

        return dfs(0,0)