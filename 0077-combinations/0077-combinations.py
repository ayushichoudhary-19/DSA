class Solution:
    def __init__(self):
        self.ans = []

    def helper(self,start,end,curr,k):
        if len(curr) == k:
            self.ans.append(curr[:])
            return

        for i in range(start,end+1):
            curr.append(i)
            self.helper(i+1,end,curr,k)
            curr.pop()

    def combine(self, n: int, k: int) -> list[list[int]]:
        self.helper(1,n,[],k)
        return self.ans