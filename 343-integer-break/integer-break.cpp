class Solution {
    
    
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        for(int i=2;i<=n;i++){
                for(int k=1;k<i;k++){
                    dp[i]=max({dp[i],k*dp[i-k],k*(i-k)});
                }
        }
        return dp[n];
    }
};