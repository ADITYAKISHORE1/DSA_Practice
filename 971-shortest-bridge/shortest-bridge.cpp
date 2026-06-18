class Solution {
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    vector<pair<int, int>> island1, island2;
    vector<vector<int>> vis;
    int n;
    bool isInsideGrid(int& nx, int& ny) {
        return (nx >= 0 and ny >= 0 and nx < n and ny < n);
    }
    void bfs(int& x, int& y, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push({x, y});
        vis[x][y] = 1;
        while (!q.empty()) {
            auto [a, b] = q.front();
            q.pop();
            island1.push_back({a,b});
            for (int i = 0; i < 4; i++) {
                int nx = a + dx[i];
                int ny = b + dy[i];
                if (isInsideGrid(nx, ny) && grid[nx][ny] == 1 &&
                    vis[nx][ny] == 0) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        vis.resize(n, vector<int>(n, 0));
        bool ck = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    if (!ck) {
                        bfs(i, j, grid);
                        ck = 1;
                    } else if (vis[i][j] == 0) {
                        island2.push_back({i, j});
                    }
                }
            }
        }

        int ans = INT_MAX;
        for (auto& [x1, y1] : island1) {
            for (auto& [x2, y2] : island2) {
                int d = abs(x2 - x1) + abs(y2 - y1) - 1;
                ans = min(ans, d);
            }
        }
        return ans;
    }
};