class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mapping = {}
        n = len(nums)

        for i in range(n):
            
            if target - nums[i] in mapping:
                return [mapping[target-nums[i]],i]
            
            else: mapping[nums[i]] = i

        return []