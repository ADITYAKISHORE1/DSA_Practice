class Solution {
    int timer = 1;
    vector<vector<int>> bridges;
    void f(int node, int parent, vector<int>& tin, vector<int>& low,
           vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;
        tin[node] = low[node] = timer++;

        for (auto& adjNode : adj[node]) {
            if (adjNode == parent)
                continue;
            if (vis[adjNode] == 0) {
                f(adjNode, node, tin, low, vis, adj);
                low[node] = min(low[node], low[adjNode]);
                if (tin[node] < low[adjNode]) {
                    bridges.push_back({node, adjNode});
                }
            } else {
                low[node] = min(low[node], low[adjNode]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto& i : connections) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n, 0);
        vector<int> tin(n);
        vector<int> low(n);
        f(0, -1, tin, low, vis, adj);
        return bridges;
    }
};