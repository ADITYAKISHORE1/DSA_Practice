class Solution {
    vector<int> vis;
    vector<int> ans;
    vector<int> dfs(int node, vector<vector<int>>& adj, string& s) {
        vis[node] = 1;
        vector<int> hsh(26, 0);
        hsh[s[node] - 'a']++;
        for (auto& adjNode : adj[node]) {
            if (vis[adjNode] == 0) {
                vector<int> t = dfs(adjNode, adj, s);
                for (int i = 0; i < 26; i++)
                    hsh[i] += t[i];
            }
        }
        ans[node] = hsh[s[node] - 'a'];
        return hsh;
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges,
                              string labels) {
        vis.resize(n, 0);
        ans.resize(n, 0);
        vector<vector<int>> adj(n);
        for (auto& i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(0, adj, labels);
        return ans;
    }
};