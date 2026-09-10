from collections import defaultdict
import heapq
class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:

        heap = [(-1,start_node)] #probability of reaching starting node is 1 so fox max heap store -1
        dist = [float('-inf')]*n
        dist[start_node] = 1 #probability of reaching starting node is 1
        adjlist = defaultdict(list) 

        for i in range(len(edges)):
            adjlist[edges[i][0]].append((edges[i][1],succProb[i]))
            adjlist[edges[i][1]].append((edges[i][0],succProb[i]))

        while heap:
            curr_prob, node = heapq.heappop(heap)
            curr_prob = -curr_prob #for max heap we store negative of actual values so make them positive again on popping them out

            if curr_prob < dist[node]:
                continue
            
            for nei, prob in adjlist[node]:
                newprob = curr_prob * prob

                if newprob > dist[nei]:
                    dist[nei] = newprob
                    heapq.heappush(heap,(-1*newprob,nei))

        # if prob is still -inf then it is not rechable
        return 0 if dist[end_node] == float('-inf') else dist[end_node]
