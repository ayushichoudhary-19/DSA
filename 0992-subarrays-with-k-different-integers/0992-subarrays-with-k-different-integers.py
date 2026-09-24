class Solution:
    def subarraysWithKDistinct(self, nums: list[int], k: int) -> int:
        
        def atMost(k):
            hashmap = {}
            count = 0
        
            i,j = 0,0

            for j in range(len(nums)):
                hashmap[nums[j]] = hashmap.get(nums[j],0) + 1

                # while it is invalid
                while len(hashmap) > k:
                    hashmap[nums[i]] -= 1

                    if hashmap[nums[i]] == 0:
                        del hashmap[nums[i]] 
                    
                    i += 1
                
                # How many valid subarrays END at j?
                count += j - i + 1

            return count
        return atMost(k) - atMost(k-1)