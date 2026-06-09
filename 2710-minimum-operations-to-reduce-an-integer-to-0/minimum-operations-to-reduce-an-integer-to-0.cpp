class Solution {
    unordered_map<long long, int> dp;
    int f(long long n, int k) {
        if (k > 31)
            return 0;
        if (n == 0) {
            return 0;
        }
        long long key = (n << 6) | k;
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }
        if ((n >> k) & 1LL) {
            return dp[key] = 1 + min(f((n + (1LL << k)), k + 1),
                                     f((n & ~(1LL << k)), k + 1));
        }
        return dp[key] = f(n, k + 1);
    }

public:
    int minOperations(int n) { 
        return f(n, 0); 
    }
};