class Solution {
    int m, n;
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    bool dfs(int x, int y, vector<vector<int>>& g1, vector<vector<int>>& g2) {
        g2[x][y] = 0;
        bool c = g1[x][y];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 and ny >= 0 and nx < m and ny < n and g2[nx][ny] == 1) {
                c &= dfs(nx, ny, g1, g2);
            }
        }
        return c;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1) {
                    if (dfs(i, j, grid1, grid2))
                        cnt++;
                }
            }
        }
        return cnt;
    }
};