class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        ans = math.inf

        if n == 1:
            if nums[0] < target:
                return 0
            else:
                return 1
    
        i, j = 0, 1
        sum = nums[0]
        currlen = 1

        while i < n and j <= n:

            if sum >= target:
                ans = min(ans, currlen)

                sum -= nums[i]
                i += 1
                currlen -= 1

            else:
                if j < n:
                    sum += nums[j]
                    j += 1
                    currlen += 1
                else:
                    break

        return 0 if ans == math.inf else ans