class Solution:
    def combinationSum3(self, k: int, n: int) -> list[list[int]]:
        
        ans = []

        def dfs(curr,val,rem):
            if rem == 0 and len(curr) == k:
                ans.append(curr[:])
                return

            if len(curr) > k or val == 10:
                return

            if rem < val:
                return

            # take
            curr.append(val)
            dfs(curr,val+1,rem-val)
            curr.pop()

            # dont take
            dfs(curr,val+1,rem)

        
        dfs([],1,n)
        return ans