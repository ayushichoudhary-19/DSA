class Solution:
    def canVisitAllRooms(self, rooms: list[list[int]]) -> bool:
        n = len(rooms)

        def dfs(key,path):

            path.add(key)
            
            if len(path) == n:
                return True


            for room in rooms[key]:
                if room in path:
                    continue
                
                if dfs(room,path):
                    return True

            return False

        return dfs(0,set())