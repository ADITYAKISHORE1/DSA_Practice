class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis = grid;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        int dist = -1;
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < n && vis[nx][ny] == 0) {
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
            dist++;
        }
        return (dist == 0) ? -1 : dist;
    }
};