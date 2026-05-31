class Solution {
    bool f(int n, int thr_wt, vector<vector<pair<int, int>>>& adj, int thr) {
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (auto& [adjWt, adjNode] : adj[node]) {
                if (adjWt <= thr_wt and vis[adjNode] == 0) {
                    q.push(adjNode);
                    vis[adjNode] = 1;
                }
            }
        }
        for (auto& i : vis)
            if (i == 0)
                return false;
        return true;
    }

public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& i : edges) {
            adj[i[1]].push_back({i[2], i[0]});
        }
        int l = 0, r = 1e9;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (f(n, mid, adj, threshold)) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};