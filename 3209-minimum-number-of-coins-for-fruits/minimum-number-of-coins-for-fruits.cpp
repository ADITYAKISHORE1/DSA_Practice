class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][0]=dp[0][1]=prices[0];
        for(int i=1;i<n;i++){
            dp[i][1]=prices[i]+min(dp[i-1][0],dp[i-1][1]);
            dp[i][0]=INT_MAX;
            for(int j=(i)/2;j<i;j++){
                dp[i][0]=min(dp[i][0],dp[j][1]);
            }
        }
        return min(dp[n-1][0],dp[n-1][1]);
    }
};
// i>=(j-1)/2
/*
3 1 2

3 3 4
3 4 5


*/