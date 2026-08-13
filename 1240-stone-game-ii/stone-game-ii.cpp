class Solution {
    int f(int i,int m,int& n,vector<int>& v,vector<vector<int>>&dp){
        if(i+2*m>=n) return v[i];
        if(dp[i][m]!=-1) return dp[i][m];

        int res=INT_MAX;
        for(int k=1;k<=2*m;k++){
            res=min(res,f(i+k,max(m,k),n,v,dp));
        }
        return dp[i][m]=v[i]-res;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        for(int i=n-2;i>=0;i--){
            piles[i]+=piles[i+1];
        }
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,1,n,piles,dp);
    }
};