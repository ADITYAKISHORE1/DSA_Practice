class Solution {
    vector<int> vis;
    vector<vector<int>> dp;
    vector<vector<int>> adj;
    bool isLoop = false;
    int n;
    vector<int> dfs(int node, string& colors) {
        if (vis[node] == 1 or isLoop) {
            isLoop = true;
            return vector<int>(26, 0);
        }
        if (vis[node] == 2)
            return dp[node];
        vis[node] = 1;
        vector<int> v(26, 0);
        for (auto& adjNode : adj[node]) {
            vector<int> child = dfs(adjNode, colors);
            for (int i = 0; i < 26; i++)
                v[i] = max(v[i], child[i]); // bcz we want to take the path
                                            // which have maxm colors component
        }
        v[colors[node] - 'a'] += 1;
        vis[node] = 2;
        return dp[node] = v;
    }

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        n = colors.size();
        dp.resize(n, vector<int>(26, -1));
        adj.resize(n);
        for (auto& i : edges) {
            adj[i[0]].push_back(i[1]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vis.resize(n, 0);
            vector<int> t = dfs(i, colors);
            if (isLoop)
                return -1;
            for (auto& i : t)
                ans = max(ans, i);
        }
        return ans;
    }
};