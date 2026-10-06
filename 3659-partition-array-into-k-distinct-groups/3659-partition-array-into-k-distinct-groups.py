class Solution:
    def partitionArray(self, nums: List[int], k: int) -> bool:

        numset = set(nums)
        n = len(nums)

        if n%k != 0:
            return False
        
        mp = {}
        for num in nums:
            mp[num] = mp.get(num,0)+1

        for num in mp:
            count = mp[num]
            if count > n/k:
                return False
        
        return True
