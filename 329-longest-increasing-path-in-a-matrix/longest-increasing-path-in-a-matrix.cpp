class Solution {
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {1, -1, 0, 0};
    vector<vector<int>> dp;
    int m, n;
    bool isUnderLim(int& nx, int& ny) {
        return (nx >= 0 and ny >= 0 and nx < m and ny < n);
    }
    int dfs(int x, int y, vector<vector<int>>& mat) {
        if (dp[x][y] != -1)
            return dp[x][y];
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isUnderLim(nx, ny) and mat[nx][ny] > mat[x][y]) {
                cnt = max(cnt, dfs(nx, ny, mat));
            }
        }
        return dp[x][y] = cnt + 1;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        dp.resize(m, vector<int>(n, -1));
        int maxm = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxm = max(maxm, dfs(i, j, matrix));
            }
        }
        return maxm;
    }
};