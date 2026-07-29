class Solution {
    vector<int> dp;
    int f(int i,vector<int>&v){
        if(i<=0) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=v[i]+f(i-2,v);        
        int notTake=f(i-1,v);
        return dp[i]=max(take,notTake);
    }
    vector<int> dp1;
    int f1(int i,vector<int>&v){
        if(i<0) return 0;
        if(dp1[i]!=-1) return dp1[i];
        int take=v[i]+f1(i-2,v);        
        int notTake=f1(i-1,v);
        return dp1[i]=max(take,notTake);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        dp.resize(n,-1);
        dp1.resize(n,-1);
        return max(f(n-1,nums),f1(n-2,nums));
    }
};