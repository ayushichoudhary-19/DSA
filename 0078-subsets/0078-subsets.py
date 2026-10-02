class Solution:
    def subsets(self, nums: list[int]) -> list[list[int]]:
        
        ans = []
        def dfs(idx,arr):
            nonlocal ans
            if idx == len(nums):
                ans.append(arr[:])
                return 
            
            dfs(idx+1,arr)
            
            arr.append(nums[idx])
            dfs(idx+1,arr)
            arr.pop()

            return
        
        dfs(0,[])
        return ans