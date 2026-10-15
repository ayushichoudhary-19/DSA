class Solution:
    def exist(self, board: list[list[str]], word: str) -> bool:
        
        m = len(board)
        n = len(board[0])
        delx = [-1,0,1,0]
        dely = [0,1,0,-1]
        visited = set()

        def dfs(row,col,idx):
            currletter = board[row][col]
            # if a word's index does not match current string index return
            if currletter != word[idx]:
                return False

            if idx == len(word)-1:
                return True

            for k in range(4):
                newrow = row+delx[k]
                newcol = col+dely[k]

                if 0<=newrow<m and 0<=newcol<n and (newrow,newcol) not in visited:
                    visited.add((newrow,newcol))
                    if dfs(newrow,newcol,idx+1):
                        return True
                    visited.remove((newrow,newcol))

            return False

        for i in range(m):
            for j in range(n):
                if board[i][j] == word[0]:
                    visited.add((i,j))
                    if dfs(i,j,0):
                        return True
                    visited.remove((i,j))

        return False