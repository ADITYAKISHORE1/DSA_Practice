class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for (auto& i : relations) {
            adj[i[0] - 1].push_back(i[1] - 1);
            indegree[i[1] - 1]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                pq.push({time[i], i});
            }
        }
        int totalTime = 0;
        while (!pq.empty()) {
            auto [tm, node] = pq.top();
            pq.pop();
            totalTime = max(totalTime, tm);
            for (auto& adjNode : adj[node]) {
                indegree[adjNode]--;
                if (indegree[adjNode] == 0) {
                    pq.push({time[adjNode] + tm, adjNode});
                }
            }
        }

        return totalTime;
    }
};