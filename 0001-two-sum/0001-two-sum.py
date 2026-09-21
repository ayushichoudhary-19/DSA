class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        hashmap = {}
        n = len(nums)
        for i in range(n):
            diff = target - nums[i]
            if diff in hashmap:
                return [hashmap[diff],i]
            else:
                hashmap[nums[i]] = i
