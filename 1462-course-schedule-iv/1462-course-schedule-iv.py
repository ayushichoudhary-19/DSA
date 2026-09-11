class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        connected = [[False]* numCourses for _ in range(numCourses)]

        for u,v in prerequisites:
            connected[u][v] = True
        
        for k in range(numCourses):
             for i in range(numCourses):
                 for j in range(numCourses):

                    connected[i][j] = connected[i][j] or connected[i][k] and connected[k][j]
        
        ans = []
        for u,v in queries:
            ans.append(connected[u][v])

        return ans