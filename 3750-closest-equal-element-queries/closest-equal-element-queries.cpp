class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }
        vector<int> ax;
        for (auto& q : queries) {
            vector<int>& ar = mpp[nums[q]];
            int m = ar.size();
            if (m == 1) {
                ax.push_back(-1);
                continue;
            }
            int lb = lower_bound(ar.begin(), ar.end(), q) - ar.begin();
            int ans = 1e9;
            int d1 = abs(ar[lb] - ar[(lb - 1 + m) % m]);
            int d2 = abs(ar[(lb + 1) % m] - ar[lb]);
            ans = min({ans, d1, n - d1, d2, n - d2});
            ax.push_back(ans);
        }
        return ax;
    }
};