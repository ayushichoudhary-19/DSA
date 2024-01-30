#include <vector>
#include <stack>

using namespace std;
void dfs(int node, stack<int> &st, vector<int> &visited, vector<int> graph[]) {
    visited[node] = 1;
    for (auto it : graph[node]) {
        if (!visited[it]) {
            dfs(it, st, visited, graph);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &adj, int edges, int nodes) {
    stack<int> st;
    vector<int> visited(nodes, 0);
    vector<int> graph[nodes];
    for(auto it:adj)
      {  graph[it[0]].push_back(it[1]);}

    for (int i = 0; i < nodes; i++) {
        if (!visited[i]) {
            dfs(i, st, visited, graph);
        }
    }

    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}
