class Solution {
    vector<int> dp;
    int f(int i,vector<int>&nums){
        if(i>=nums.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=1e9;
        for(int j=1;j<=nums[i];j++){
            take=min(take,1+f(i+j,nums));
        }
        return dp[i]=take;
    }
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,-1);
        return f(0,nums);
    }
};
