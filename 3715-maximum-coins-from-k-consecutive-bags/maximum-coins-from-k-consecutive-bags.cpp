class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        int l = 0, r = 0;
        long long maxAmount = 0;
        long long curAmount = 0;
        while (l < n) {
            while (r < n and coins[r][1] <= k + coins[l][0] - 1) {
                curAmount +=
                    1LL * (coins[r][1] - coins[r][0] + 1) * coins[r][2];
                r++;
            }
            if (r < n) {
                long long partial =
                    1LL*max(0, k + coins[l][0] - 1 - coins[r][0] + 1) * coins[r][2];
                maxAmount = max(maxAmount, curAmount + partial);
            }
            curAmount -= 1LL * (coins[l][1] - coins[l][0] + 1) * coins[l][2];
            l++;
        }
        curAmount = 0;
        l = 0, r = 0;
        while (r < n) {
            curAmount += 1LL*(coins[r][1] - coins[r][0]+1) * coins[r][2];
            while (l < r and coins[l][1] < coins[r][1] - k + 1) {
                curAmount -= 1LL * (coins[l][1] - coins[l][0]+1) * coins[l][2];
                l++;
            }
            long long partial =
                1LL*max(0, coins[r][1] - k - coins[l][0] + 1) * coins[l][2];
            maxAmount = max(maxAmount, curAmount - partial);
            r++;
        }
        return maxAmount;
    }
};