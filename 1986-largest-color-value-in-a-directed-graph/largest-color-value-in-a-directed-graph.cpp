class Solution {
    vector<int> vis;
    vector<vector<int>> dp;
    vector<vector<int>> adj;
    int n;
    int dfs(int node, int col, string& colors) {
        if (vis[node] == 1) {
            return -1;
        }
        if (dp[node][col] != -1)
            return dp[node][col];
        vis[node] = 1;
        int take = 0;
        for (auto& adjNode : adj[node]) {
            int child = dfs(adjNode, col, colors);
            if(child==-1) return -1;
            take = max(take, child);
        }
        vis[node] = 2;
        take += (colors[node]-'a'==col);
        return dp[node][col] = take;
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
        for (int c = 0; c < 26; c++) {
            vis.resize(n, 0);
            for (int i = 0; i < n; i++) {
                int t = dfs(i, c, colors);
                if (t == -1)
                    return -1;
                ans = max(ans, t);
            }
        }
        return ans;
    }
};