class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<long long> cur(n, 0);
        vector<long long> prev(n, 0);
        cur[n - 1] = prev[n - 1] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1) {
                    cur[j] = 0;
                    continue;
                }
                if (i == m - 1 and j == n - 1) {
                    cur[j] = 1;
                    continue;
                }
                cur[j] = 0;
                if (i < m - 1) {
                    cur[j] += prev[j];
                }
                if (j < n - 1) {
                    cur[j] += cur[j + 1];
                }
            }
            prev = cur;
        }
        return prev[0];
    }
};