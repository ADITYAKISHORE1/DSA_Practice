class Solution {
    vector<long long> dijkstra(int n, int src,
                               vector<vector<pair<int, int>>>& adj) {
        vector<long long> dist(n, 1e18);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<>>
            pq;
        pq.push({0, src});
        dist[src] = 0;
        while (!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();
            if(dis>dist[node]) continue;
            for (auto& [adjNode, d] : adj[node]) {
                if (dist[adjNode] > dis + d) {
                    dist[adjNode] = d + dis;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }

public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1,
                            int src2, int dest) {
        vector<vector<pair<int, int>>> adj(n);
        vector<vector<pair<int, int>>> revadj(n);
        for (auto& i : edges) {
            adj[i[0]].push_back({i[1], i[2]});
            revadj[i[1]].push_back({i[0], i[2]});
        }
        // dist of src1 to all other node
        vector<long long> v1 = dijkstra(n, src1, adj);
        // dist of src2 to all other node
        vector<long long> v2 = dijkstra(n, src2, adj);
        // dist of dest to all other node in reversed graph
        vector<long long> v3 = dijkstra(n, dest, revadj);
        long long mn = 1e18;
        for (int i = 0; i < n; i++) {
            mn = min(mn, v1[i] + v2[i] + v3[i]);
        }
        return (mn == 1e18) ? -1 : mn;
    }
};