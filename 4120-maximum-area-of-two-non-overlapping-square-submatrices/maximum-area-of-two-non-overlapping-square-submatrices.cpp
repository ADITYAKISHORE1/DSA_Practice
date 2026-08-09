class Solution {
    bool pred(int k,vector<vector<int>>& dp){
        int minr=INT_MAX,minc=INT_MAX;
        int maxr=0,maxc=0;
        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[0].size();j++){
                if(dp[i][j]>=k){
                    minr=min(minr,i);
                    maxr=max(maxr,i);
                    minc=min(minc,j);
                    maxc=max(maxc,j);
                }
            }
        }
        return ((maxc-minc)>=k ||(maxr-minr)>=k);
    }
public:
    int maxArea(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]){
                    dp[i+1][j+1]=min({dp[i][j],dp[i+1][j],dp[i][j+1]})+1;
                }
            }
        }

        int l=0,r=min(m,n);
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(pred(mid,dp)){
                ans=mid;
                l=mid+1;
            }else r=mid-1;
        }
        return ans*ans;
    }
};