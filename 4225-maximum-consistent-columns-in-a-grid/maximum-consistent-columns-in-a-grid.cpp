class Solution {
    int m, n;
    vector<vector<int>> dp;
    int f(int i, int k, vector<vector<int>>& v, int lim) {
        if (i < 0)
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];
        bool t = true;
        if (k != n) {
            for (int j = 0; j < m; j++) {
                int x = abs(v[j][i] - v[j][k]);
                if (x > lim) {
                    t = false;
                    break;
                }
            }
        }
        int take = 0;
        if (t) {
            take = 1 + f(i - 1, i, v, lim);
        }
        int notTake = f(i - 1, k, v, lim);
        return dp[i][k] = max(take, notTake);
    }

public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        m = grid.size();
        n = grid[0].size();
        dp.resize(n + 1, vector<int>(n + 1, -1));
        return f(n - 1, n, grid, limit);
    }
};