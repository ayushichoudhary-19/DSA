class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        n = len(nums)


        i,j = 0,0

        count = set()

        while j < n:
            if j - i > k:
                count.remove(nums[i])
                i+=1
            
            if nums[j] in count:
                return True
            count.add(nums[j])
            j+=1

        return False


            