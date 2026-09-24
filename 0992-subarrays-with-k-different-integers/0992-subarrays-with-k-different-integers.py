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

        # atmost k means array has k = 3 means 3 types, atmost k-1 means atmost 2 distinct, so one with 1,2,3 distincts - 1,2 distincts is gonna be equal to exactly 3 distincts
        return atMost(k) - atMost(k-1)