class Solution {
    vector<vector<int>> dp;
    int f(int n,int amt,vector<int>& coins){
        if(n<0) return 0;
        if(amt==0) return 1;
        if(dp[n][amt]!=-1) return dp[n][amt];
        int take=0;
        if(coins[n]<=amt){
            take=f(n,amt-coins[n],coins);
        }
        int notTake=f(n-1,amt,coins);
        return dp[n][amt]=take+notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins);
    }
};