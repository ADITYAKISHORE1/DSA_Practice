class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 2, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i < n + 2; i++) {
            if (s[i - 2] != '0') {
                dp[i] += dp[i - 1];
            }
            if (i > 2) {
                int val = stoi(s.substr(i - 3, 2));
                if (val >= 10 and val <= 26) {
                    dp[i] += dp[i - 2];
                }
            }
        }
        return dp[n + 1];
    }
};