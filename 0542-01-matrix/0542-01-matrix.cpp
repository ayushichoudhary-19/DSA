class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>> q;
        int m=mat.size();int n=mat[0].size();
        vector<vector<int>> ans=mat;
        //add all 0's to the queue
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(ans[i][j]==0){
                    q.push({{i,j},0});
                }
                else{
                    ans[i][j]=-1;
                }
            }
        }
        
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && ans[nrow][ncol]==-1){
                    q.push({{nrow,ncol},dis+1});
                    ans[nrow][ncol]=dis+1;
                }
            }
        }
        return ans;
    }
};