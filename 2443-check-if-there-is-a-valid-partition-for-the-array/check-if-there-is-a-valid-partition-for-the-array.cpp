class Solution {
    bool f(int i,vector<int>&v,vector<int>&dp){
        if(i<0) return true;
        if(i==0) return false;
        if(i==1){
            return v[0]==v[1];
        }
        if(dp[i]!=-1) return dp[i];
        bool take=0;
        if(v[i-1]==v[i]){
            take=1&f(i-2,v,dp);
        }
        if(v[i-2]==v[i-1] and v[i-1]==v[i]){
            take|=(1&f(i-3,v,dp));
        }
        if(v[i-2]==v[i-1]-1 and v[i-1]==v[i]-1){
            take|=(1&f(i-3,v,dp));
        }
        return dp[i]=take;
    }
public:
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(n-1,nums,dp);
    }
};