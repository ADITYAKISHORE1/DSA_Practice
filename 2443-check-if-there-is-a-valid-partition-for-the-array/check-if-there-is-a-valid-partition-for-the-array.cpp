class Solution {
    bool f(int i, vector<int>& v, vector<int>& dp) {
        if (i < 0)
            return true;
        if (i == 0)
            return false;
        if (i == 1) {
            return v[0] == v[1];
        }
        if (dp[i] != -1)
            return dp[i];
        bool take = 0;
        if (v[i - 1] == v[i]) {
            take = 1 & f(i - 2, v, dp);
        }
        if (v[i - 2] == v[i - 1] and v[i - 1] == v[i]) {
            take |= (1 & f(i - 3, v, dp));
        }
        if (v[i - 2] == v[i - 1] - 1 and v[i - 1] == v[i] - 1) {
            take |= (1 & f(i - 3, v, dp));
        }
        return dp[i] = take;
    }

public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        // return f(n-1,nums,dp);
        dp[1] = (nums[0] == nums[1]);
        if(n==2) return dp[1];
        dp[2] = (nums[0] == nums[1] and nums[1]==nums[2])|(nums[0]+1 == nums[1] and nums[1]+1==nums[2]);
        for (int i = 3; i < n; i++) {
            if (nums[i - 1] == nums[i]) {
                dp[i] = 1 & dp[i - 2];
            }
            if (nums[i - 2] == nums[i - 1] and nums[i - 1] == nums[i]) {
                dp[i] |= (1 & dp[i - 3]);
            }
            if (nums[i - 2] == nums[i - 1] - 1 and nums[i - 1] == nums[i] - 1) {
                dp[i] |= (1 & dp[i - 3]);
            }
        }
        return dp[n-1];
    }
};