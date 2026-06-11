class Solution {
    const int MOD = 1e9 + 7;

public:
    int kInversePairs(int n, int k) {
        vector<long long> cur(k + 1, 0), prev(k + 1, 0);
        prev[0] = 1;
        for (int i = 1; i <= n; i++) {
            cur[0] = 1;
            for (int j = 1; j <= k; j++) {
                cur[j] = prev[j - min(j, i - 1)];
                if (j + 1 <= k) {
                    cur[j] = (cur[j] - prev[j + 1] + MOD) % MOD;
                }
            }
            prev = cur;
            for (int l = k - 1; l >= 0; l--) {
                prev[l] = (prev[l] + prev[l + 1]) % MOD;
            }
        }
        return prev[k];
    }
};