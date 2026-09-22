class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        hashmap ={0:1}
        prefixsum = 0
        count = 0
        for num in nums:
            prefixsum = num + prefixsum
            diff = prefixsum - k
            
            if diff in hashmap:
                count += hashmap[diff]
                
            hashmap[prefixsum] = hashmap.get(prefixsum,0) + 1

        return count


        