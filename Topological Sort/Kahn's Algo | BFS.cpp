#include<queue>
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    queue<int> q;
    vector<int> indegree(nodes,0);
    vector<int> ans;
    vector<vector<int>> adj(nodes);

    for (auto edge : graph) {
        indegree[edge[1]]++;
        adj[edge[0]].push_back(edge[1]);
    }

    for(int i=0;i<nodes;i++){
        if(indegree[i]==0) q.push(i);
    }

    while(!q.empty()){
        int node=q.front();
        ans.push_back(node);
        q.pop();
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    return ans;
    
}
