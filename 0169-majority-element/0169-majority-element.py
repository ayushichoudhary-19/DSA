class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        
        freq = 1
        ans = nums[0]
        for i in range(1,n):
            if(nums[i] == nums[i-1]):
                freq+=1
                ans = nums[i]
            else:
                if(freq > n/2):
                    return ans
                else:
                    freq = 1

        return ans
        
    
