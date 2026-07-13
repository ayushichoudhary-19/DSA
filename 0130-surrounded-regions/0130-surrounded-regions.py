class Solution:
    def solve(self, board: L==t[L==t[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        
        m = len(board)
        n = len(board[0])

        delx = [0,1,0,-1]
        dely = [-1,0,1,0]

        def dfs(x,y,board):
            newx = x
            newy = y
            for k in range(4):
                newx = x + delx[k]
                newy = y + dely[k]

                if newx >= 0 and newx < m and newy>=0 and newy < n and board[newx][newy] == 'O':
                    board[newx][newy] = '#'
                    dfs(newx,newy,board)

        #traverse the 4 corners
        i,j = 0,0
        for i in range(m):
            if board[i][j] == 'O':
                board[i][j] = '#'
                dfs(i,j,board)

        j = n-1
        for i in range(m):
            if board[i][j] == 'O':
                board[i][j] = '#'
                dfs(i,j,board)

        i = 0
        for j in range(n):
            if board[i][j] == 'O':
                board[i][j] = '#'
                dfs(i,j,board)

        i = m-1
        for j in range(n):
            if board[i][j] == 'O':
                board[i][j] = '#'
                dfs(i,j,board)


        #fill the whole board with correct values

        for i in range(m):
            for j in range(n):
                if board[i][j] == '#':
                    board[i][j] = 'O'
                else:
                    board[i][j] = 'X' 