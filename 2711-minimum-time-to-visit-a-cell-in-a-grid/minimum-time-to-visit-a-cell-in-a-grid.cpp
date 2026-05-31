class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (m > 1 && n > 1 && grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        vector<vector<int>> vis(m, vector<int>(n, 0));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;

        pq.push({0, 0, 0});

        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};

        while (!pq.empty()) {
            auto [t, x, y] = pq.top();
            pq.pop();

            if (vis[x][y])
                continue;
            vis[x][y] = 1;

            if (x == m - 1 && y == n - 1)
                return t;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n || vis[nx][ny])
                    continue;

                int nt = t + 1;

                if (nt < grid[nx][ny]) {
                    int dif = grid[nx][ny] - nt;
                    if (dif & 1) {
                        nt = grid[nx][ny] + 1;
                    } else
                        nt = grid[nx][ny];
                }

                pq.push({nt, nx, ny});
            }
        }

        return -1;
    }
};