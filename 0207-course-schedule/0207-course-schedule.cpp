class Solution {
private:
    vector<int> toposort(vector<vector<int>> &adj, int numCourses){
        queue<int> q;
        vector<int> ans;
        vector<int> indegree(numCourses,0);
        for (auto nodes : adj) {
            for (auto node : nodes) {
                indegree[node]++;
            }
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
            }
        }
        return ans;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto edge:prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }

        //now detect cycle
        vector<int> topo=toposort(adj,numCourses);
        if(topo.size()<numCourses){
            return false;
        }
        return true;
    }
};