class Solution {
    unordered_map<long long, unordered_map<long long, long long>> dp;
    int f(long long n, int k) {
        if (k > 31)
            return 0;
        if (n == 0) {
            return 0;
        }
        if (dp.find(n) != dp.end() && dp[n].find(k) != dp[n].end()) {
            return dp[n][k];
        }
        int one = 0;
        if ((n >> k) & 1LL) {
            one = 1 +
                  min(f((n + (1LL << k)), k + 1), f((n & ~(1LL << k)), k + 1));
        } else {
            one = f(n, k + 1);
        }
        return dp[n][k] = one;
    }

public:
    int minOperations(int n) {
        // dp.resize(1e5,vector<int>(63,-1));
        return f(n, 0);
    }
};