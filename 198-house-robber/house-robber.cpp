class Solution {
    vector<vector<int>> dp;
    int f(int i,bool t,vector<int>&v){
        if(i<0) return 0;
        if(dp[i][t]!=-1) return dp[i][t];
        int take=0;
        if(t){
            take=v[i]+f(i-1,false,v);
        } 
        int notTake=f(i-1,true,v);
        return dp[i][t]=max(take,notTake);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,vector<int>(2,-1));
        return f(n-1,true,nums);
    }
};