class Solution:
    def checkSubarraySum(self, nums: list[int], k: int) -> bool:
        #looks like a variation of subarray sum equals k
        # additional idea: If two prefix sums have the same remainder when divided by k, their difference is divisible by k.
        
        # The key idea is:
            # prefix1 % k == prefix2 % k
            # means:
            # (prefix2 - prefix1) % k == 0

        # WE ASK: Have I seen this remainder before?

        hashmap = {0: -1}
        currsum = 0

        for i in range(len(nums)):
            currsum = currsum + nums[i]
            rem = currsum % k

            if rem in hashmap:
                #condition of atleast 2 len
                if i - hashmap[rem] >= 2:
                    return True
            else:
                hashmap[rem] = i

        return False