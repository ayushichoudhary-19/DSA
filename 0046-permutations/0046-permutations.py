class Solution:
    def permute(self, nums: list[int]) -> list[list[int]]:
        

        ans = []

        used = set()


        def dfs(curr,used):
            if len(used) == len(nums):
                ans.append(curr[:])
                return

            for num in nums:
                if num not in used:
                    curr.append(num)
                    used.add(num)
                    dfs(curr,used)
                    curr.pop()
                    used.remove(num)
        
        dfs([],used)

        return ans

