class Solution {
    const int MOD = 1e9 + 7;
    long long powr(long long base, int exp, int limit) {
        long long ans = 1;

        while (exp > 0) {
            if (exp & 1) {
                ans *= base;
                if (ans > limit)
                    return limit + 1;
            }

            exp >>= 1;

            if (exp) {
                base *= base;
                if (base > limit)
                    base = limit + 1;
            }
        }

        return ans;
    }

public:
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));
        for (int i = 0; i <= n + 1; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = n; j >= 1; j--) {
                long long ways = 0;

                for (int k = j; k <= n; k++) {
                    long long v = powr(k, x, i);

                    if (v > i)
                        break;

                    ways = (ways + dp[i - v][k + 1]) % MOD;
                }

                dp[i][j] = ways;
            }
        }
        return dp[n][1] % MOD;
    }
};