class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums.sort()
        n = len(nums)
        i,j,k = 0,0,0
        target = 0
        ans = []
        
        for i in range(n-2):
            if i > 0 and nums[i]==nums[i-1]:
                continue
            j = i+1
            k = n-1
            while j<k:
                if nums[j]+nums[k] == -nums[i]:
                    ans.append([nums[i],nums[j],nums[k]])
                    j += 1
                    k -= 1
                    # Skip duplicate second elements
                    while j < k and nums[j] == nums[j - 1]:
                        j += 1

                    # Skip duplicate third elements
                    while j < k and nums[k] == nums[k + 1]:
                        k -= 1
                elif nums[j]+nums[k] > -nums[i]:
                    k -= 1
                else:
                    j += 1
            
        return ans


