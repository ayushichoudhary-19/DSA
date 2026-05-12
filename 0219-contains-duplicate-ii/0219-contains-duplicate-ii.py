class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        n = len(nums)


        i,j = 0,0

        mapping = {}

        while j < n:
            if nums[j] in mapping:
                return True
                
            else: 
                mapping[nums[j]] = 1
                j += 1
            
            if len(mapping) > k:
                del mapping[nums[i]]
                i += 1

        return False


            