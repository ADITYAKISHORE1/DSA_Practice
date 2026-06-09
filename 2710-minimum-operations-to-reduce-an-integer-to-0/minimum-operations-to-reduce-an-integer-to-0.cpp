class Solution {
    unordered_map<long long, int> dp;
    int f(long long n) {
        if ((n & (n - 1)) == 0)
            return 1;
        if (n == 0) {
            return 0;
        }
        if (dp.find(n) != dp.end()) {
            return dp[n];
        }
        long long lowbit = n & -n;
        return dp[n] = 1 + min(f(n + lowbit), f(n - lowbit));
    }

public:
    int minOperations(int n) { return f(n); }
};