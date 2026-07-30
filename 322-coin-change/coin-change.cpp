class Solution {
    vector<vector<long long>> dp;
    int f(int n,long long amt,vector<int>& coins){
        if(amt<0) return 1e9;
        if(amt==0) return 0;
        if(n<0) return 1e9;
        if(dp[n][amt]!=-1) return dp[n][amt];
        long long take=1+f(n,amt-coins[n],coins);
        long long notTake=f(n-1,amt,coins);
        return dp[n][amt]=min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        dp.resize(n,vector<long long>(amount+1,-1));
        long long ans=f(n-1,amount,coins);
        return ans>=1e9?-1:ans;
    }
};