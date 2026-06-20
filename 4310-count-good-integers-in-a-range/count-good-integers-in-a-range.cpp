class Solution {
    long long dp[20][2][2][10];
    long long f(int i, bool tight, bool started, int digit, vector<int>& v,
                int k) {
        if (i == v.size())
            return 1;
        if(dp[i][tight][started][digit]!=-1) return dp[i][tight][started][digit];
        long long take = 0;
        int lim = (tight) ? v[i] : 9;
        for (int d = 0; d <= lim; d++) {
            int ntight = (tight && (d == v[i]));
            if (!started and d == 0) {
                take += f(i + 1, ntight, 0, d, v, k);
            } else if (!started) {
                take += f(i + 1, ntight, 1, d, v, k);
            } else if (abs(d - digit) <= k) {
                take += f(i + 1, ntight, 1, d, v, k);
            }
        }
        return dp[i][tight][started][digit]=take;
    }

public:
    long long goodIntegers(long long l, long long r, int k) {
        vector<int> vl;
        l--;
        while (l != 0) {
            vl.push_back(l % 10);
            l /= 10;
        }
        vector<int> vr;
        while (r != 0) {
            vr.push_back(r % 10);
            r /= 10;
        }
        reverse(vl.begin(), vl.end());
        reverse(vr.begin(), vr.end());
        memset(dp,-1,sizeof(dp));
        long long a = f(0, 1, 0, 0, vl, k);
        memset(dp,-1,sizeof(dp));
        long long b = f(0, 1, 0, 0, vr, k);
        return b - a;
    }
};