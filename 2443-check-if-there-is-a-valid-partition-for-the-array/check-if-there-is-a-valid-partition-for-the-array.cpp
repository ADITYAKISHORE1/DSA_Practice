class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[1] = !(nums[0] ^ nums[1]);
        if (n == 2)
            return dp[1];
        dp[2] = (!(nums[0] ^ nums[1]) & !(nums[1] ^ nums[2])) |
                (!((nums[0] + 1) ^ nums[1]) & !((nums[1] + 1) ^ nums[2]));
        for (int i = 3; i < n; i++) {
            dp[i] = (!(nums[i - 1] ^ nums[i]) & dp[i - 2]) |
                    ((!(nums[i - 2] ^ nums[i - 1]) & !(nums[i - 1] ^ nums[i]) &
                      dp[i - 3])) |
                    ((!(nums[i - 2] ^ (nums[i - 1] - 1)) &
                      !(nums[i - 1] ^ (nums[i] - 1))) &
                     dp[i - 3]);
        }
        return dp[n - 1];
    }
};