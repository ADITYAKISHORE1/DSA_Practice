class Solution {
    vector<vector<int>> dp;
    bool f(int i, int j, int k, string& s1, string& s2, string& s3) {
        if (k < 0 and i < 0 and j < 0) {
            return true;
        }
        if (i > 0 and j > 0 and dp[i][j] != -1)
            return dp[i][j];
        if (i >= 0 and s1[i] == s3[k] and j >= 0 and s2[j] == s3[k]) {
            return dp[i][j] = f(i - 1, j, k - 1, s1, s2, s3) |
                              f(i, j - 1, k - 1, s1, s2, s3);
        } else if (j >= 0 and s2[j] == s3[k]) {
            return f(i, j - 1, k - 1, s1, s2, s3);
        } else if (i >= 0 and s1[i] == s3[k]) {
            return f(i - 1, j, k - 1, s1, s2, s3);
        }
        return false;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), mn = s3.size();
        if (m + n != mn)
            return false;
        dp.resize(m, vector<int>(n, -1));
        return f(m - 1, n - 1, mn - 1, s1, s2, s3);
    }
};