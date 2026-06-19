class Solution {
    vector<int> dx = {0, 0, 1, -1, 1, 1, -1, -1};
    vector<int> dy = {1, -1, 0, 0, -1, 1, 1, -1};
    int m, n;
    void dfs(int x, int y, vector<vector<char>>& board) {
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 and ny >= 0 and nx < m and ny < n and
                board[nx][ny] == 'M') {
                cnt++;
            }
        }
        board[x][y] = (cnt == 0) ? 'B' : (cnt + '0');
        if (cnt != 0)
            return;
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 and ny >= 0 and nx < m and ny < n and
                board[nx][ny] == 'E') {
                dfs(nx, ny, board);
            }
        }
    }

public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                     vector<int>& click) {
        m = board.size();
        n = board[0].size();
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        dfs(click[0], click[1], board);
        return board;
    }
};