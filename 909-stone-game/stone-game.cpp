class Solution {
    vector<vector<int>> dp;
    int f(int l,int r,vector<int>&v){
        if(l>r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int takel=v[l]-f(l+1,r,v);
        int taker=v[r]-f(l,r-1,v);
        return dp[l][r]=max(takel,taker);
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        dp.resize(n,vector<int>(n,-1));
        return f(0,n-1,piles);
    }
};