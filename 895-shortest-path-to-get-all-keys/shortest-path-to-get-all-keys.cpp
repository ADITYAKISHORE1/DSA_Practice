class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<vector<int>> q; // {x,y,steps,curr_key_state}

        int cnt_key = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    q.push({i, j, 0, 0});

                } else {
                    if (grid[i][j] >= 'a' and grid[i][j] <= 'f') {
                        cnt_key++;
                    }
                }
            }
        }
        int target_key_state = pow(2, cnt_key) - 1;

        vector<vector<vector<int>>> vis(
            m, vector<vector<int>>(n, vector<int>(target_key_state + 1, 0)));

        vis[q.front()[0]][q.front()[1]][q.front()[3]] = 1;

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        while (!q.empty()) {
            auto i = q.front();
            q.pop();
            int x = i[0], y = i[1], cur_steps = i[2], cur_key_state = i[3];
            if (cur_key_state == target_key_state)
                return cur_steps;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 and nx < m and ny >= 0 and ny < n and
                    grid[nx][ny]!= '#') {
                    char c = grid[nx][ny];
                    if (c >= 'a' and c <= 'f') {
                        int new_key_state = (cur_key_state | (1 << (c - 'a')));
                        if (vis[nx][ny][new_key_state] == 0) {
                            vis[nx][ny][new_key_state] = 1;
                            q.push({nx, ny, cur_steps + 1, new_key_state});
                        }
                    } else if (c >= 'A' and c <= 'F') {
                        if (vis[nx][ny][cur_key_state] == 0 and
                            ((cur_key_state >> (c - 'A')) & 1) == 1) {
                            vis[nx][ny][cur_key_state] = 1;
                            q.push({nx, ny, cur_steps + 1, cur_key_state});
                        }
                    } else {
                        if (vis[nx][ny][cur_key_state] == 0) {
                            vis[nx][ny][cur_key_state] = 1;
                            q.push({nx, ny, cur_steps + 1, cur_key_state});
                        }
                    }
                }
            }
        }
        return -1;
    }
};