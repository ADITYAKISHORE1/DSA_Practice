class Solution {
    vector<vector<int>> dp;
    int f(int i,int j,vector<int>&v){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0;
        for(int k=i;k<=j;k++){
            take=max(take,v[i-1]*v[k]*v[j+1]+f(i,k-1,v)+f(k+1,j,v));
        }
        return dp[i][j]=take;
    }
public:
    int maxCoins(vector<int>& nums) {
        vector<int> v;
        v.push_back(1);
        for(auto &i:nums) v.push_back(i);
        v.push_back(1);
        int n=v.size();
        dp.resize(n,vector<int>(n,-1));
        return f(1,n-2,v);
    }
};