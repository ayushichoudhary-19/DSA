class Solution:
    def maximalNetworkRank(self, n: int, roads: list[list[int]]) -> int:
        degree = [0] * n
        # a set of tuples for O(1) lookups
        edge_set = set()
        # we use set of tuples bec TypeError: cannot use 'list' as a set element (unhashable type: 'list')
        
        for u, v in roads:
            degree[u] += 1
            degree[v] += 1
            # store both directions since roads are undirected
            edge_set.add((u, v))
            edge_set.add((v, u))

        maxRank = 0

        for i in range(n):
            for j in range(i + 1, n):
                # O(1) lookup in the set
                is_connected = 1 if (i, j) in edge_set else 0
                network_rank_i_j = degree[i] + degree[j] - is_connected
                maxRank = max(maxRank, network_rank_i_j)

        return maxRank
