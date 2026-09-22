class Solution:
    def subarraysDivByK(self, nums: list[int], k: int) -> int:
        
        hashmap = {0:1}
        count = 0
        currsum = 0

        for i in range(len(nums)):
            currsum += nums[i]

            rem = currsum % k

            if rem in hashmap:
                count += hashmap[rem]

            hashmap[rem] = hashmap.get(rem,0) + 1

        return count
