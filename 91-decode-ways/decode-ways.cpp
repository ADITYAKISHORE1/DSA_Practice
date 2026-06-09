class Solution {
    vector<int> dp;
    int f(int n, string& s) {
        if (n < 0)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        int one = 0;
        if (s[n] != '0') {
            one = f(n - 1, s);
        }
        if (n > 0) {
            int val = stoi(s.substr(n - 1, 2));
            if (val >= 10 and val <= 26) {
                one += f(n - 2, s);
            }
        }
        return dp[n] = one;
    }

public:
    int numDecodings(string s) {
        int n = s.size();
        dp.resize(n, -1);
        return f(n - 1, s);
    }
};