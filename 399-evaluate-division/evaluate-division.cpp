class Solution {
    double dijkstra(string u, string v, unordered_map < string,
                    vector<pair<string, double>>>& adj) {
        queue<pair<double, string>> pq;
        pq.push({1, u});
        unordered_map<string, double> dist;
        while (!pq.empty()) {
            auto p = pq.front();
            pq.pop();
            if (p.second == v)
                return p.first;
            for (auto& aj : adj[p.second]) {
                string st = aj.first;
                double d = aj.second;
                if (!dist.count(st)) {
                    dist[st] = (p.first * d);
                    pq.push({dist[st], st});
                }
            }
        }
        return -1;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map < string, vector<pair<string, double>>> adj;
        for (int i = 0; i < equations.size(); i++) {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            double val = 1.0 / values[i];
            adj[equations[i][1]].push_back({equations[i][0], val});
        }
        vector<double> ans;
        for (auto& i : queries) {
            if (!adj.count(i[0]) or !adj.count(i[1])) {
                ans.push_back(-1);
                continue;
            }
            double v = dijkstra(i[0], i[1], adj);
            ans.push_back(v);
        }
        return ans;
    }
};