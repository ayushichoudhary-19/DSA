class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0])

        ans = []
        n = len(intervals)


        prev = intervals[0]
        if n == 1:
            return [prev]

        for i in range(1,n+1):
            prevStart = prev[0]
            prevEnd = prev[1]

            if i<n:
                currStart = intervals[i][0]
                currEnd = intervals[i][1]

                if currStart <= prevEnd:
                    prev = [prevStart, max(currEnd,prevEnd)]

                else:
                    ans.append(prev)
                    prev = intervals[i]
            else:
                ans.append(prev)

        return ans
            
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        intervals.append(newInterval)
        return self.merge(intervals)
        