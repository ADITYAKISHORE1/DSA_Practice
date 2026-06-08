class Solution {
public:
    long long minimumCost(string s) {
        int n = s.size();
        if (n == 1)
            return 0;
        vector<long long> pref(n), suf(n);
        long long ans = LLONG_MAX;
        pref[0] = 0;
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1];
            if (s[i] != s[i - 1]) {
                pref[i] += i;
            }
        }
        suf[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = suf[i + 1];
            if (s[i] != s[i + 1]) {
                suf[i] += n - i - 1;
            }
            ans = min(ans, suf[i] + pref[i]);
        }
        return ans;
    }
};