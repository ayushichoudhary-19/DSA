class Solution
{
  private:
    void bfs(int node, vector<vector<int>> &adjlist, vector<int> &vis) {
        vis[node] = 1;

        queue<int> q;
        q.push(node);

        while(!q.empty()){
          node = q.front();
          q.pop();

          for(auto neigh: adjlist[node]){
            if(!vis[neigh]){
              vis[neigh] = 1;
              q.push(neigh);
            }
          }
        }
    }
    int findNumberOfComponent(int V, vector<vector<int>> &adjlist) {
      vector<int> vis(V, 0);

      int cnt = 0;

      for(int i = 0; i < V; i++){
          if(!vis[i]){
              cnt++;
              // Perform BFS traversal
              bfs(i, adjlist, vis);
          }
      }
      return cnt;
    }


  public:
    int findCircleNum(vector<vector<int>> adj) {
        int V=adj.size();
        
        vector<vector<int>> adjL(V);

        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(adj[i][j]==1 && i!=j){
                    adjL[i].push_back(j);
                } 
            }
        }
        return findNumberOfComponent(V,adjL);
    }
};
