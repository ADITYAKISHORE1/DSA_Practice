class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0), dp(k, 0);
        for (auto& num : nums) {
            int x = num % k;
            vector<long long> next(k, 0);
            next[x]++;
            for (int r = 0; r < k; r++) {
                int newR = (r * (num % k)) % k;
                next[newR] += dp[r];
            }
            for (int i = 0; i < k; i++) {
                ans[i] += next[i];
            }
            dp = next;
        }
        return ans;
    }
};