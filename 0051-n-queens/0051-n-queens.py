class Solution:

    def solveNQueens(self, n: int) -> list[list[str]]:
        
        ans = []

        def checkPlacementAllowed(board,row,col):
            # checks if we can place a queen in curr row or col

            # if curr col or curr row or diagonal of curr row or col has a Q return false

            for i in range(0,row):
                if board[i][col] == 'Q':
                    return False
        
            for i in range(1, row + 1):
                if col - i >= 0: 
                    if board[row - i][col - i] == 'Q':
                        return False

            n = len(board)
            for i in range(1, row + 1):
                if col + i < n:
                    if board[row - i][col + i] == 'Q':
                        return False

            return True

        def dfs(board,row):

            if row==n:
                ans.append([''.join(row) for row in board])
                return

            for j in range(n):

                if 0<=j<n and 0<=row<n and checkPlacementAllowed(board,row,j):
                    board[row][j] = 'Q'
                    dfs(board,row+1)
                    board[row][j] = '.'

        board = [['.'] * n for _ in range(n)]


        dfs(board,0)
        
        return ans