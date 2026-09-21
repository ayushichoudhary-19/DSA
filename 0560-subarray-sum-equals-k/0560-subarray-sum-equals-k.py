class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = 0
        prefixsum = 0

        hashmap = {0:1}

        for num in nums:
            prefixsum += num

            if prefixsum - k in hashmap:
                count += hashmap[prefixsum - k]
            
            hashmap[prefixsum] = hashmap.get(prefixsum,0) + 1
    
        return count