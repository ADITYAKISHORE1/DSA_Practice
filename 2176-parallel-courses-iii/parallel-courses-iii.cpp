class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for (auto& i : relations) {
            adj[i[0] - 1].push_back(i[1] - 1);
            indegree[i[1] - 1]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push( i);
            }
        }
        vector<int> incMax(n,0);
        int totalTime = 0;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int tm=incMax[node]+time[node];
            totalTime = max(totalTime, tm);
            for (auto& adjNode : adj[node]) {
                indegree[adjNode]--;
                incMax[adjNode]=max(incMax[adjNode],tm);
                if (indegree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }

        return totalTime;
    }
};