class Solution {
    pair<long long, long long> t;
    vector<vector<int>> adj;
    int seats;
    pair<long long, long long> dfs(int node, int parNode) {
        long long person = 1;
        long long cost = 0;
        for (auto& adjNode : adj[node]) {
            if (adjNode != parNode) {
                t = dfs(adjNode, node);
                person += t.first;
                cost += t.second;
            }
        }
        cost += (person + seats - 1) / seats;
        return make_pair(person, cost);
    }

public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        adj.resize(n);
        this->seats = seats;
        for (auto& i : roads) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        long long ans = 0;
        for (auto& i : adj[0]) {
            ans += dfs(i, 0).second;
        }
        return ans;
    }
};