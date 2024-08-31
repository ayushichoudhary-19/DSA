class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);

        double maxi = 0.0;
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double> prob(n, 0.0);
        prob[start_node] = 1.0;
        
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});

        while(!pq.empty()){
            double currProb = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (node == end_node) return currProb;
            
            for (auto& neighbor : adj[node]) {
                int nextNode = neighbor.first;
                double edgeProb = neighbor.second;

                if (currProb * edgeProb > prob[nextNode]) {
                    prob[nextNode] = currProb * edgeProb;
                    pq.push({prob[nextNode], nextNode});
                }
            }
        }
        return 0.0;
    }
};