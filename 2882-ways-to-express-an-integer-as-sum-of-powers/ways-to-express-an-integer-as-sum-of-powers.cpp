class Solution {
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    int f(int n, int i, int x) {
        if (n == 0)
            return 1;
        if (dp[n][i] != -1)
            return dp[n][i];
        long long take = 0;
        for (int p = i; p <= n; p++) {
            int v = pow(p, x);
            if (n >= v ) {
                take = (take + f(n - v, p + 1, x)) % MOD;
            } else
                break;
        }
        return dp[n][i] = take % MOD;
    }

public:
    int numberOfWays(int n, int x) {
        dp.resize(n + 1, vector<int>(n + 1, -1));
        return f(n, 1, x)%MOD;
    }
};