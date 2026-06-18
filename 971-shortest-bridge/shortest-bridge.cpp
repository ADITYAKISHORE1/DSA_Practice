class Solution {
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    queue<pair<int, int>> q1;
    int n;
    bool isInsideGrid(int& nx, int& ny) {
        return (nx >= 0 and ny >= 0 and nx < n and ny < n);
    }
    void bfs(int& sx, int& sy, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push({sx, sy});
        grid[sx][sy]=2;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            q1.push({x, y});
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (isInsideGrid(nx, ny) && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        bool found = 0;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    bfs(i, j, grid);
                    found = 1;
                }
            }
        }
        int dist = 0;
        while (!q1.empty()) {
            int sz = q1.size();
            while (sz--) {
                auto [x, y] = q1.front();
                q1.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (isInsideGrid(nx, ny)) {
                        if (grid[nx][ny] == 0) {
                            grid[nx][ny]=2;
                            q1.push({nx, ny});
                        } else if (grid[nx][ny] == 1)
                            return dist;
                    }
                }
            }
            dist++;
        }
        return dist;
    }
};