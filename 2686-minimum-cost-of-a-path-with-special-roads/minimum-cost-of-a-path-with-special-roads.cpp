class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target,
                    vector<vector<int>>& specialRoads) {
        unordered_map<int, unordered_map<int, vector<tuple<int, int, int>>>>
            adj;
        adj[start[0]][start[1]].push_back(
            {abs(target[0] - start[0]) + abs(target[1] - start[1]), target[0],
             target[1]});
        for (auto& i : specialRoads) {
            adj[start[0]][start[1]].push_back(
                {abs(i[0] - start[0]) + abs(i[1] - start[1]), i[0], i[1]});
            adj[i[0]][i[1]].push_back({i[4], i[2], i[3]});
            adj[i[2]][i[3]].push_back(
                {abs(target[0] - i[2]) + abs(target[1] - i[3]), target[0],
                 target[1]});
        }
        for (int i = 0; i < specialRoads.size(); i++) {
            for (int j = 0; j < specialRoads.size(); j++) {
                if (i == j)
                    continue;
                adj[specialRoads[i][2]][specialRoads[i][3]].push_back(
                    {abs(specialRoads[i][2] - specialRoads[j][0]) +
                         abs(specialRoads[j][1] - specialRoads[i][3]),
                     specialRoads[j][0], specialRoads[j][1]});
                adj[specialRoads[j][2]][specialRoads[j][3]].push_back(
                    {abs(specialRoads[j][2] - specialRoads[i][0]) +
                         abs(specialRoads[i][1] - specialRoads[j][3]),
                     specialRoads[i][0], specialRoads[i][1]});
            }
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;
        unordered_map<int, unordered_map<int, int>> vis;
        pq.push({0, start[0], start[1]});
        // vis[start[0]][start[1]]=1;
        while (!pq.empty()) {
            auto [wt, x, y] = pq.top();
            pq.pop();
            if (vis[x][y])
                continue;
            vis[x][y] = 1;
            if (x == target[0] and y == target[1])
                return wt;
            for (auto& [curWt, curX, curY] : adj[x][y]) {
                if (vis[curX][curY] == 0) {
                    pq.push({wt + curWt, curX, curY});
                    // vis[curX][curY]=1;
                }
            }
        }
        return -1;
    }
};