class Solution {
    vector<int> dp;
    int f(int amt, vector<int>& coins) {
        if (amt == 0)
            return 0;

        if (dp[amt] != -1)
            return dp[amt];
        dp[amt] = 1e9;
        for (auto& c : coins) {
            int take = INT_MAX;
            if (c <= amt)
                take = 1 + f(amt - c, coins);
            dp[amt] = min(take, dp[amt]);
        }
        return dp[amt];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.resize(amount + 1, -1);
        int ans = f(amount, coins);
        return ans >= 1e9 ? -1 : ans;
    }
};