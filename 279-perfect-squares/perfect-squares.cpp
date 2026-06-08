class Solution {
    // int f(int i, int n) {
    //     if (i <= 0 or n < 0)
    //         return 1e9;
    //     if (n == 0)
    //         return 0;
    //     int take  = 1 + f(i, n - i * i);
    //     int notTake = f(i - 1, n);
    //     return min(take, notTake);
    // }

public:
    int numSquares(int n) {
        int v = sqrt(n);
        vector<vector<int>> dp(v+1,vector<int>(n+1,1e9));
        for(int i=0;i<=n;i++) dp[0][i]=1e9;
        for(int i=0;i<=v;i++) dp[i][0]=0;
        for(int i=1;i<=v;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=i*i){
                    dp[i][j]=min(dp[i][j],1+dp[i][j-i*i]);
                }
            }
        }
        return dp[v][n];
    }
};