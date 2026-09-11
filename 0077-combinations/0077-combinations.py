class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        
        ans = []

        def dfs(index):
            if len(curr) == k:
                ans.append(curr[:])
                return
            
            if index == n+1:
                return

            for i in range(index,n+1):
                curr.append(i)
                dfs(i+1)
                curr.pop()
            
        index = 1
        curr = []
        dfs(index)
        return ans