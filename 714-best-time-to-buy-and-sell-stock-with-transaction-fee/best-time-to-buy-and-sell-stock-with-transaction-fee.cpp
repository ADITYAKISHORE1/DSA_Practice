class Solution {
    vector<vector<int>> dp;
    int f(int n,int buy,int fee,vector<int>&v){
        if(n==v.size()) return 0;
        if(dp[n][buy]!=-1) return dp[n][buy];
        int take=0;
        if(buy){
            take=-v[n]-fee+f(n+1,0,fee,v);
        }else{
            take=v[n]+f(n+1,1,fee,v);
        }
        int notTake=f(n+1,buy,fee,v);
        return dp[n][buy]=max(take,notTake);
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        dp.resize(prices.size(),vector<int>(2,-1));
        return f(0,1,fee,prices);
    }
};