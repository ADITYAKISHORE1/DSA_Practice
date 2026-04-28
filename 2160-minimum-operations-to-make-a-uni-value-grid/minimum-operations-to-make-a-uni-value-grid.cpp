class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        for (auto& i : grid)
            for (auto& j : i)
                v.push_back(j);
        sort(v.begin(), v.end());
        int n = v.size();
        int l = max(0, (n / 2) - 1), r = (n / 2);
        int ans = INT_MAX;
        int az = 0;
        for (auto i : v) {
            int a = abs(i - v[l]);
            if (a % x != 0) {
                az = 1e9;
                break;
            }
            az += a/x;
        }
        int ay = 0;
        for (auto i : v) {
            int a = abs(i - v[r]);
            if (a % x != 0) {
                ay = 1e9;
                break;
            }
            ay += a/x;
        }
        ans = min(az, ay);
        if (ans == 1e9)
            return -1;
        return ans;
    }
};