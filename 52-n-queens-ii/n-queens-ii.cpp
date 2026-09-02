class Solution {
    int cnt=0;
    void f(int i, int& n, vector<int>& leftRow,
           vector<int>& upDiag, vector<int>& downDiag) {
        if (i == n) {
            cnt++;
            return;
        }
        for (int j = 0; j < n; j++) {
            if (leftRow[j] == 1 or upDiag[n - 1 + i - j] == 1 or
                downDiag[i + j] == 1)
                continue;
            leftRow[j] = 1;
            upDiag[n - 1 + i - j] = 1;
            downDiag[i + j] = 1;
            f(i + 1, n, leftRow, upDiag, downDiag);
            leftRow[j] = 0;
            upDiag[n - 1 + i - j] = 0;
            downDiag[i + j] = 0;
        }
    }
public:
    int totalNQueens(int n) {
        vector<int> leftRow(n, 0);
        vector<int> upDiag(2 * n, 0);
        vector<int> downDiag(2 * n, 0);
        f(0, n, leftRow, upDiag, downDiag);
        return cnt;
    }
};