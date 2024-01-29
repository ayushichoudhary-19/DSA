class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited,int row, int col){
      int m=board.size();
      int n=board[0].size();
      int delrow[]={-1,0,1,0};
      int delcol[]={0,1,0,-1};

      for(int i=0;i<4;i++){
          int nrow=row+delrow[i];
          int ncol=col+delcol[i];
          if(nrow>=0 && nrow<m && ncol>0 && ncol<n && board[nrow][ncol]=='O' && !visited[nrow][ncol]){
            visited[nrow][ncol]=1;
            dfs(board,visited,nrow,ncol);
          }
      }
    }
    void solve(vector<vector<char>>& board) {
      int rows=board.size();
      int cols=board[0].size();
      vector<vector<int>> visited(rows,vector<int> (cols,0));

     //   check top border
     for(int i=0;i<cols;i++){
        if(board[0][i]=='O'){
            visited[0][i]=1;
            dfs(board,visited,0,i);
        }
    }
    //   check right border
     for(int i=0;i<rows;i++){
        if(board[i][cols-1]=='O'){
            visited[i][cols-1]=1;
            dfs(board,visited,i,cols-1);
        }
    }
     //   check bottom border
     for(int i=0;i<cols;i++){
        if(board[rows-1][i]=='O'){
            visited[rows-1][i]=1;
            dfs(board,visited,rows-1,i);
        }
    }

        //   check left border
     for(int i=0;i<rows;i++){
        if(board[i][0]=='O'){
            visited[i][0]=1;
            dfs(board,visited,i,0);
        }
    }
    
    // flip
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(!visited[i][j]){
                board[i][j]='X';
            }
            else{
                board[i][j]='O';
            }
        }
    }
    }
};