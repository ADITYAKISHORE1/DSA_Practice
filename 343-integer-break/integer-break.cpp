class Solution {
    vector<vector<int>> dp;
    int f(int n,int k){
        if(n==0){
            if(k>=2) return 1;
            return 0;
        }
        if(dp[n][k>=2]!=-1) return dp[n][k>=2];
        for(int i=1;i<=n;i++){
            dp[n][k>=2]=max(dp[n][k>=2],i*f(n-i,k+1));
        }
        return dp[n][k>=2];
    }
public:
    int integerBreak(int n) {
        dp.resize(n+1,vector<int>(2,-1));
        return f(n,0);
    }
};