class Solution {
    const int MOD=1e9+7;
    
    // long long f(int n,int k){
    //     if(n==0) return 0;
    //     if(k==0) return 1;
    //     if(dp[n][k]!=-1) return dp[n][k];
    //     long long take=0;
    //     for(int i=0;i<=min(k,n-1);i++){
            
    //         take=(take+f(n-1,k-i))%MOD;
    //     }
    //     return dp[n][k]=take;
    // }
public:
    int kInversePairs(int n, int k) {
        // vector<vector<long long>> dp(n+1,vector<long long>(k+1,0));
        vector<long long> cur(k+1,0),prev(k+1,0);
        // for(int i=1;i<=n;i++) dp[i][0]=1;
        prev[0]=1;
        for(int i=1;i<=n;i++){
            fill(cur.begin(),cur.end(),0);
            cur[0]=1;
            for(int j=1;j<=k;j++){
                for(int l=0;l<=min(j,i-1);l++){
                    cur[j]=(cur[j]+prev[j-l])%MOD;
                }
            }
            prev=cur;
        }
        // return dp[n][k]%MOD;
        return prev[k];
    }
};