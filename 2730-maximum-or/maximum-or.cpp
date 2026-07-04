class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> sufOR(n, 0);
        for (int i = n - 2; i >= 0; i--) {
            sufOR[i] = sufOR[i + 1] | nums[i + 1];
        }
        vector<long long> prefOR(n, 0);
        for (int i = 1; i < n; i++) {
            prefOR[i] = prefOR[i - 1] | nums[i - 1];
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long v = prefOR[i] | sufOR[i];
            long long val = nums[i];
            for (int j = 0; j <= k; j++) {
                ans = max(ans, v | val);
                val <<= 1;
            }
        }
        return ans;
    }
};