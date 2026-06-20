class Solution {
    long long dp[16][2][2][10];
    long long f(int i, bool tight, bool started, int prevDigit, vector<int>& v,
                int k) {
        if(i==v.size()) return 1;
        if(dp[i][tight][started][prevDigit]!=-1) return dp[i][tight][started][prevDigit];
        long long take = 0;
        int lim = (tight) ? v[i] : 9;
        for (int d = 0; d <= lim; d++) {
            int ntight = (tight && d == v[i]);
            if (!started) {
                take += f(i + 1, ntight, (d != 0), d, v, k);
            } else if (abs(d - prevDigit) <= k) {
                take += f(i + 1, ntight, 1, d, v, k);
            }
        }
        return dp[i][tight][started][prevDigit]=take;
    }

public:
    long long goodIntegers(long long l, long long r, int k) {
        vector<int> vl, vr;
        l--;
        while (l) {
            vl.push_back(l % 10);
            l /= 10;
        }
        while (r) {
            vr.push_back(r % 10);
            r /= 10;
        }
        reverse(vl.begin(),vl.end());
        reverse(vr.begin(),vr.end());
        memset(dp,-1,sizeof(dp));
        long long ans = f(0, 1, 0, 0, vr, k);
        memset(dp,-1,sizeof(dp));
        ans-=f(0, 1, 0, 0, vl, k);
        return ans;
    }
};