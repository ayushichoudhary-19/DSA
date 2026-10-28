class Solution:
    def permuteUnique(self, nums: list[int]) -> list[list[int]]:
        nums.sort()
        ans = []
        used = [False] * len(nums)

        def dfs(curr):
            if len(curr) == len(nums):
                ans.append(curr[:])
                return

            for i in range(len(nums)):
                if used[i]:
                    continue

                if i > 0 and nums[i] == nums[i - 1] and not used[i - 1]:
                    continue

                used[i] = True
                curr.append(nums[i])
                dfs(curr)
                curr.pop()
                used[i] = False
        
        dfs([])

        return ans
