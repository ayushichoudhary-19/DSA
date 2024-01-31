vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {
    // queue for bfs
    queue<pair<int,int>> q;

    vector<vector<int>> adj(n);
    for(auto edge:edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    // distance vector
    vector<int> dist(n,101);

    // put source in the queue
    dist[src]=0;
    q.push({src,0});

    // traverse the graph
    while(!q.empty()){
        int node=q.front().first;
        int d=q.front().second;
        q.pop();
        
        for(auto neighbour:adj[node]){
        // Check if the new distance is smaller than the current distance
            if(dist[neighbour]>d+1){
            dist[neighbour]=d+1;
            q.push({neighbour,dist[neighbour]});
            }
        }
    }
    for(int i=0;i<n;i++){
        if(dist[i]==101) dist[i]=-1;
    }
    return dist;

}
