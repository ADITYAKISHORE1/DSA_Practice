class Solution {
public:
    long long countFairPairs(vector<int>& v, int lower, int upper) {
        int n = v.size();
        sort(v.begin(), v.end());
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            int lb = lower_bound(v.begin(), v.end(), lower - v[i]) - v.begin();
            int ub =
                upper_bound(v.begin(), v.end(), upper - v[i]) - v.begin() - 1;
            if (lb == n or ub < 0)
                continue;
            if (v[lb] + v[i] >= lower and v[ub] + v[i] <= upper) {
                cnt += ub - lb + 1;
            }
            if (i >= lb and i <= ub)
                cnt--;
        }
        return cnt / 2;
    }
};