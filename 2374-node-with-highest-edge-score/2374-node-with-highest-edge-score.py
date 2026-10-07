class Solution:
    def edgeScore(self, edges: list[int]) -> int:

        n = len(edges)
        nodeSum = [0]*n

        for i in range(n):
            nodeSum[edges[i]] += i
        
        maxSum = nodeSum[0]
        maxSumNode = 0

        for i in range(1,n):
            if nodeSum[i] > maxSum:
                maxSum = nodeSum[i]
                maxSumNode = i

        return maxSumNode