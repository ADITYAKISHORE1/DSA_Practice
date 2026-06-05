class Solution {
    const int MOD = 1e9 + 7;

public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency,
                       int k) {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({efficiency[i], speed[i]});
        sort(v.rbegin(), v.rend());
        priority_queue<int, vector<int>, greater<>> sp;
        long long sum = 0;
        long long ans = 0;
        for (auto& [eff, spd] : v) {
            sum += spd;
            sp.push(spd);
            if (sp.size() > k) {
                sum -= sp.top();
                sp.pop();
            }
            ans = max(ans, (1LL * sum * eff));
        }
        return ans % MOD;
    }
};
