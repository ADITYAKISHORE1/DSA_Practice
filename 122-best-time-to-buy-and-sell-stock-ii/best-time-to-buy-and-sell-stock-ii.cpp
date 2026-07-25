class Solution {
    vector<vector<int>> dp;
    int f(int i, bool b, vector<int>& v) {
        if (i == v.size()) {
            if (!b) {
                return -1e9;
            }
            return 0;
        }
        if(dp[i][b]!=-1) return dp[i][b];
        int take = 0;
        if (b) {
            take = -v[i] + f(i + 1, !b, v);
        } else {
            take = v[i] + f(i + 1, !b, v);
        }
        int notTake = f(i + 1, b, v);
        return dp[i][b]=max(take, notTake);
    }

public:
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),vector<int>(2,-1));
        return f(0,1,prices);
    }
};