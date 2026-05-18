class Solution {
    unordered_map<int, vector<int>> mpp;

public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            mpp[arr[i]].push_back(i);
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<int> vis(n, 0);
        vis[0] = 1;
        int ans = INT_MAX;
        while (!q.empty()) {
            auto [idx, d] = q.front();
            q.pop();
            if (idx == n - 1)
                return d;
            if (idx > 0 and vis[idx - 1] == 0) {
                vis[idx - 1] = 1;
                q.push({idx - 1, d + 1});
            }
            if (idx < n - 1 and vis[idx + 1] == 0) {
                vis[idx + 1] = 1;
                q.push({idx + 1, d + 1});
            }
            for (auto i : mpp[arr[idx]]) {
                if (vis[i] == 0) {
                    vis[i] = 1;
                    q.push({i, d + 1});
                }
            }
            mpp[arr[idx]].clear();
        }
        return -1;
    }
};