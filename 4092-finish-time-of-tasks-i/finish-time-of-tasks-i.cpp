class Solution {
    long long dfs(int node, vector<vector<int>>& adj, vector<int>& baseTime) {
        if (adj[node].empty())
            return baseTime[node];
        long long latest = 0, earliest = LLONG_MAX;
        for (auto& adjNode : adj[node]) {
            long long t = dfs(adjNode, adj, baseTime);
            latest = max(latest, t);
            earliest = min(earliest, t);
        }
        return (baseTime[node] + (latest - earliest)+latest);
    }

public:
    long long finishTime(int n, vector<vector<int>>& edges,
                         vector<int>& baseTime) {
        vector<vector<int>> adj(n);
        for (auto& i : edges) {
            adj[i[0]].push_back(i[1]);
        }
        return dfs(0, adj, baseTime);
    }
};