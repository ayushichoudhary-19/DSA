class Solution {
private:
    void dfs(int node, vector<int> &visited, vector<vector<int>>adjlist){
        visited[node]=1;
        for(int i=0;i<adjlist[node].size();i++){
            int neig=adjlist[node][i];
         if(!visited[neig]){
              dfs(neig,visited,adjlist);
         }
        }

    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adjlist(n+1);
        //convert the matrix to adjlist
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j)
                   adjlist[i+1].push_back(j+1);
                }
        
        }
        int provinces=0;
        vector<int> visited(n+1,0);
    //travese over the adjlist
        for(int i=1;i<=n;i++){
             if(!visited[i]){
                dfs(i,visited,adjlist);
                 provinces++;
             }
        }
        return provinces;
    }
};