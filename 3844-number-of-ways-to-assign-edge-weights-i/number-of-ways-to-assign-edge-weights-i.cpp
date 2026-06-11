class Solution {
    const int MOD = 1e9 + 7;
    long long expo(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) {
                res = res * a % MOD;
            }
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = 0;
        for (auto& i : edges)
            n = max({n, i[0], i[1]});
        vector<vector<int>> adj(n + 1);
        for (auto& i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        queue<int> q;
        vector<long long> dist(n + 1, INT_MAX);
        q.push(1);
        dist[1] = 0;
        long long maxmDist = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            maxmDist = max(maxmDist, dist[node]);
            for (auto& adjNode : adj[node]) {
                if (dist[adjNode] > dist[node]+1) {
                    dist[adjNode] = dist[node] + 1;
                    q.push(adjNode);
                }
            }
        }
        long long ans = expo(2, maxmDist - 1);
        return ans % MOD;
    }
};