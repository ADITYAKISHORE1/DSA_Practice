class Solution {
    vector<vector<int>> dp;
    int f(int l,int r,vector<int>& v){
        if(l>r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int t=INT_MAX;
        int idx=0;
        for(int k=l;k<=r;k++){
            t=min(t,v[r+1]-v[l-1]+f(l,k-1,v)+f(k+1,r,v));
        }
        return dp[l][r]=t;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int m=cuts.size();
        dp.resize(m,vector<int>(m,-1));
        sort(cuts.begin(),cuts.end());
        return f(1,m-2,cuts);
    }
};