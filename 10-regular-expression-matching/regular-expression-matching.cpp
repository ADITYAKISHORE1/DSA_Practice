class Solution {
    vector<vector<int>> dp;

    bool f(int i, int j, string& s, string& p) {
        if (j == p.size())
            return i == s.size();

        if (dp[i][j] != -1)
            return dp[i][j];

        bool firstMatch = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        bool ans;

        if (j + 1 < p.size() && p[j + 1] == '*') {
            ans = f(i, j + 2, s, p);
            if (firstMatch)
                ans |= f(i + 1, j, s, p); 
        } else {
            ans = firstMatch && f(i + 1, j + 1, s, p);
        }

        return dp[i][j] = ans;
    }

public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        dp.assign(m + 1, vector<int>(n + 1, -1));
        return f(0, 0, s, p);
    }
};