class Solution:
    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        
        ans = []

        def dfs(idx, curr, remaining):

            if remaining == 0:
                ans.append(curr[:])
                return

            if remaining < 0 or idx == len(candidates):
                return
            

            # include
            num = candidates[idx]
            curr.append(num)
            dfs(idx,curr,remaining-num)
            curr.pop()

            #exclude
            dfs(idx+1,curr,remaining)

            return

        dfs(0,[],target)
        return ans

            