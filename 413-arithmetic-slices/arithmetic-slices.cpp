class Solution {
    vector<int> dp;
    int f(int i,vector<int>&v){
        if(i<=1){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        if( v[i]-v[i-1]==v[i-1]-v[i-2]) return dp[i]= 1+f(i-1,v);        
        return dp[i]=0;
    }
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;
        dp.resize(n,-1);
        int ans=0;
        for (int i = 2; i < n; i++) {
            ans += f(i,nums);
        }
        return ans;
    }
};