class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        // reverse the graph
        vector<vector<int>> revgraph(n);
        for(int i=0;i<n;i++){
            for(auto node:graph[i]){
                revgraph[node].push_back(i);
            }
        }

        // now for Kahn's algo keep a queue and an indegree vector
        queue<int> q;
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto node:revgraph[i]){
                indegree[node]++;
            }
        }

        //everything with indegree 0 goes to the queue
        for(int i=0;i<n;i++){
            if(indegree[i]==0){q.push(i);}
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:revgraph[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
        }
        }

        // now all those with indegree 0 are the terminal nodes
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) ans.push_back(i);
        }
        return ans;
        }

};