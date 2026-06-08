class Solution {
public:
    long long minimumCost(string s) {
        int n = s.size();
        if (n == 1)
            return 0;
        vector<long long> pref(n);
        long long ans = LLONG_MAX;
        pref[0] = 0;
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1];
            if (s[i] != s[i - 1]) {
                pref[i] += i;
            }
        }
        long long suf=0;
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] != s[i + 1]) {
                suf += n - i - 1;
            }
            ans = min(ans, suf + pref[i]);
        }
        return ans;
    }
};