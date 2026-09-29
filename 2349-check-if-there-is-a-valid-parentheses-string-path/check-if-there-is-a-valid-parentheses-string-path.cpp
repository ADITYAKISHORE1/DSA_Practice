class Solution {
    int m, n;
    vector<vector<vector<int>>> dp;
    bool f(int i, int j, int c, vector<vector<char>>& v) {
        if (i == m or j == n)
            return false;

        if (v[i][j] == '(')
            c++;
        else
            c--;

        if (c < 0)
            return false;

        if (i == m - 1 and j == n - 1)
            return (c == 0);

        if (dp[i][j][c] != -1)
            return dp[i][j][c];

        bool right = f(i + 1, j, c, v);
        bool down = f(i, j + 1, c, v);

        return dp[i][j][c] = right | down;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if (grid[0][0] == ')' or grid[m - 1][n - 1] == '(')
            return false;

        dp.resize(m, vector<vector<int>>(n, vector<int>(m + n + 1, -1)));
        return f(0, 0, 0, grid);
    }
};