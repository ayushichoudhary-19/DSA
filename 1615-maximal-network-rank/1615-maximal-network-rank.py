class Solution:
    def maximalNetworkRank(self, n: int, roads: list[list[int]]) -> int:
        
        degree = [0]*n

        for u,v in roads:
            degree[u] += 1
            degree[v] += 1

        maxRank = 0

        for i in range(n):
            for j in range(i+1,n):
                network_rank_i_j = degree[i] + degree[j] - (1 if [i,j] in roads or [j,i] in roads else 0)
                maxRank = max(maxRank,network_rank_i_j)

        return maxRank

