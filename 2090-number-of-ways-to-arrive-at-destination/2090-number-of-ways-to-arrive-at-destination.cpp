class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);

        // Priority queue to store {time, node} with smallest time first
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        // Building the adjacency list
        for (auto& road : roads) {
            adj[road[0]].push_back({road[2], road[1]});
            adj[road[1]].push_back({road[2], road[0]});
        }

        vector<long long> time(n, LLONG_MAX);
        vector<int> ways(n, 0);

        time[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long t = pq.top().first;
            int nextNode = pq.top().second;
            pq.pop();

            // If the current time is greater than the recorded time, skip this node
            if (t > time[nextNode]) continue;

            // Explore neighbors
            for (auto& [travelTime, neighbor] : adj[nextNode]) {
                if (t + travelTime < time[neighbor]) {
                    time[neighbor] = t + travelTime;
                    ways[neighbor] = ways[nextNode];
                    pq.push({time[neighbor], neighbor});
                } else if (t + travelTime == time[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[nextNode]) % MOD;
                }
            }
        }

        return ways[n-1];
    }
};
