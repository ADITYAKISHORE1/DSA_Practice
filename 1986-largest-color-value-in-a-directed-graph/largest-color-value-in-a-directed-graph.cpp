class Solution {
    vector<int> vis;
    vector<vector<int>> dp;
    vector<vector<int>> adj;
    vector<int> indegree;
    int n;
    vector<int> dfs(int node, string& colors) {
        if (dp[node][0] != -1)
            return dp[node];
        vector<int> v(26, 0);
        for (auto& adjNode : adj[node]) {
            vector<int> child= dfs(adjNode, colors);
            for(int i=0;i<26;i++) v[i]=max(v[i],child[i]); //bcz we want to take the path which have maxm colors component
        }
        v[colors[node] - 'a'] += 1;
        return dp[node] = v;
    }
    bool isLoop() {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& adjNode : adj[node]) {
                indegree[adjNode]--;
                if (indegree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }
        for (auto& i : indegree)
            if (i > 0)
                return true;
        return false;
    }

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        n = colors.size();
        vis.resize(n, 0);
        dp.resize(n, vector<int>(26, -1));
        adj.resize(n);
        indegree.resize(n, 0);
        for (auto& i : edges) {
            indegree[i[1]]++;
            adj[i[0]].push_back(i[1]);
        }
        if (isLoop())
                return -1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> t = dfs(i, colors);
            for (auto& i : t)
                ans = max(ans, i);
        }
        return ans;
    }
};