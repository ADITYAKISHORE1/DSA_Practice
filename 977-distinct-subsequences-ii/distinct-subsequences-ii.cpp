class Solution {
    const int MOD = 1e9 + 7;
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        vector<int> last(26, -1);
        for (int i = 0; i < n; i++) {
            dp[i + 1] = (2LL * dp[i]) % MOD;
            if (last[s[i] - 'a'] != -1) {
                dp[i + 1] = (dp[i + 1] - dp[last[s[i] - 'a']] + MOD) % MOD;
            }
            last[s[i] - 'a'] = i;
        }
        return (dp[n] - 1 + MOD) % MOD;
    }
};