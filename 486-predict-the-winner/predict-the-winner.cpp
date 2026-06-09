class Solution {
    vector<vector<vector<long long>>> dp;
    // calculating score of the player 1
    long long f(int l,int r,bool player,vector<int>&v){
        if(l>r) return 0;
        if(dp[l][r][player]!=-1) return dp[l][r][player];
        int left=f(l+1,r,!player,v);
        int right=f(l,r-1,!player,v);
        if(player==0){
            return dp[l][r][player]=max(left+v[l],right+v[r]); //player 1 try to select the maximum sum state
        }
        return dp[l][r][player]=min(left,right); // player 2 will play optimally and try to return minimum state
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,vector<vector<long long>>(n,vector<long long>(2,-1)));
        long long tsum=accumulate(nums.begin(),nums.end(),0);
        long long sum=f(0,n-1,0,nums);
        // cout<<asum;
        return 2*sum>=tsum;
    }
};