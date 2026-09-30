class Solution:
    def uniquePaths(self, m: int, n: int) -> int:

        prev = [1] * n #last row

        for row in range(m-2,-1,-1):
            curr = [1] * n
            for col in range(n-2,-1,-1):
                curr[col] = prev[col] + curr[col+1]
            prev = curr

        return  prev[0]