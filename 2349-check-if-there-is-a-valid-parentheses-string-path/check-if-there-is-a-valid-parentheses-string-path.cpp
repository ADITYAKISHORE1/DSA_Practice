class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dp[101][101][202];
        memset(dp, 0, sizeof(dp));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (int c = 0; c <= m + n; c++) {
                    int cnt = c;
                    if (grid[i][j] == '(') {
                        cnt++;
                    } else {
                        cnt--;
                    }
                    if (cnt < 0)
                        continue;
                    if (i == m - 1 and j == n - 1) {
                        dp[i][j][c] = (cnt == 0);
                        continue;
                    }
                    if (i + 1 < m)
                        dp[i][j][c] |= dp[i + 1][j][cnt];
                    if (j + 1 < n)
                        dp[i][j][c] |= dp[i][j + 1][cnt];
                }
            }
        }
        return dp[0][0][0];
    }
};