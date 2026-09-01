class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        
        # if it is a boundary component, don't change else change

        # mark the boundary component diferently to make sure they never change
        # change rest of the board

        m = len(board)
        n = len(board[0])

        delx = [0,1,0,-1]
        dely = [-1,0,1,0]

        def dfs(i,j):
            board[i][j] = '#'
            for k in range(4):
                newx = i+delx[k]
                newy = j+dely[k]

                if newx >= 0 and newx < m and newy >= 0 and newy <n:
                    if board[newx][newy] == 'O':
                        dfs(newx,newy)

        # top boundary
        for j in range(n):
            if board[0][j] == 'O':
                dfs(0,j)
            
        # bottom bondary
        for j in range(n):
            if board[m-1][j] == 'O':
                dfs(m-1,j)

        # left boundary
        for i in range(m):
            if board[i][0] == 'O':
                dfs(i,0)

        # right boundary
        for i in range(m):
            if board[i][n-1] == 'O':
                dfs(i,n-1)

        # mark flagged ones as 'O' rest 'X'

        for i in range(m):
            for j in range(n):
                if board[i][j] == '#':
                    board[i][j] = 'O'
                else:
                    board[i][j] = 'X'