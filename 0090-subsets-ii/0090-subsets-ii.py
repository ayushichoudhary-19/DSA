class Solution:
    def subsetsWithDup(self, nums: list[int]) -> list[list[int]]:
        nums.sort()
        ans = []

        def dfs(start, arr):
            ans.append(arr[:])

            for i in range(start, len(nums)):

                if i > start and nums[i] == nums[i - 1]:
                    continue

                arr.append(nums[i])
                dfs(i + 1, arr)
                arr.pop()

        dfs(0, [])
        return ans