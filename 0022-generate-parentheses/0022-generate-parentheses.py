class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        
        ans = []

        def dfs(curr,opencount,closecount):

            if opencount < closecount or opencount > n:
                return

            if len(curr) == 2*n:
                ans.append("".join(curr))
                return
            
            #add open
            dfs(curr+'(',opencount+1,closecount)

            #add close
            dfs(curr+')',opencount,closecount+1)

            return

        dfs('',0,0)
        return ans