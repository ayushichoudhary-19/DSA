class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort()
        n = len(points)
        prevInterval = points[0]
        i = 1
        arrows = 1

        for i in range(1,n):
            if points[i][0] > prevInterval[1]:
                arrows += 1
                prevInterval = points[i]
            
            else:
                prevInterval = [
                    max(points[i][0],prevInterval[0]),
                    min(points[i][1],prevInterval[1])
                    ]
                
            
        return arrows
        