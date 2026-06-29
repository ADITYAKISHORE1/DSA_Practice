class Solution {
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    int m, n;
    int dfs(int x, int y, vector<vector<int>>& v) {
        int cur = v[x][y];
        v[x][y] = 0;
        int maxm = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 and ny >= 0 and nx < m and ny < n and v[nx][ny] != 0) {
                maxm = max(maxm, dfs(nx, ny, v));
            }
        }
        v[x][y] = cur;
        return v[x][y] + maxm;
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxm = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    maxm = max(maxm, dfs(i, j, grid));
                }
            }
        }
        return maxm;
    }
};