class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);
        for (auto& i : edges) {
            indegree[i[1]]++;
            adj[i[0]].push_back(i[1]);
        }
        vector<vector<int>> dp(n, vector<int>(26, 0));
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                dp[i][colors[i] - 'a'] = 1;
            }
        }
        int ans = 0;
        int processedNode = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            processedNode++;
            for (int i = 0; i < 26; i++) {
                ans = max(ans, dp[node][i]);
            }
            for (auto& adjNode : adj[node]) {
                for (int col = 0; col < 26; col++) {
                    dp[adjNode][col] =
                        max(dp[node][col] + (col == colors[adjNode] - 'a'),
                            dp[adjNode][col]);
                }
                indegree[adjNode]--;
                if (indegree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }
        return (processedNode == n) ? ans : -1;
    }
};