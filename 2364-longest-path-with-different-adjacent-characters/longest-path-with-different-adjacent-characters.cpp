class Solution {
    int ans = 0;
    int dfs(int node, int parNode, vector<vector<int>>& adj, string& s) {
        int longest = 0;
        int secLongest = 0;
        for (auto& adjNode : adj[node]) {
            if (adjNode != parNode) {
                int tmp = dfs(adjNode, node, adj, s);
                if (s[adjNode] != s[node]) {
                    if (tmp > longest) {
                        secLongest=longest;
                        longest = tmp;
                    } else
                        secLongest = max(secLongest, tmp);
                }
            }
        }
        ans = max(ans, longest + secLongest + 1);
        return longest + 1;
    }

public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1)
                adj[parent[i]].push_back(i);
        }
        dfs(0, -1, adj, s);
        return ans;
    }
};