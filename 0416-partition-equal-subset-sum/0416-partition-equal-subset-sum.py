class Solution:
    def canPartition(self, nums: list[int]) -> bool:
        
        n = len(nums)

        # if total sum, then dividing in 2 subsets of equal sum means each subset has sum total/2
        # so we need ot find a subset in array that sums up to total/2
        total = sum(nums)

        if total%2 != 0: return False #odd sum can not be divided into two equal sums

        target = int(total/2)

        prev = [False]*(target+1)
        
        prev[target] = True

        for idx in range(n-1,-1,-1):
            curr = [False]*(target+1)
            for currsum in range(target-1,-1,-1):
                    take = False
                    if currsum + nums[idx] <= target:
                        take = prev[currsum+nums[idx]]

                    dont_take = prev[currsum]

                    curr[currsum] = take or dont_take

            prev = curr

        return prev[0]