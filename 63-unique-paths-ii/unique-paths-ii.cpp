class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<long long>> dp(m,vector<long long>(n,0));
        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=-1;
                    continue;
                }
                if(i==m-1 and j==n-1) continue;
                if(i<m-1){
                    dp[i][j]+=(dp[i+1][j]==-1)?0:dp[i+1][j];
                }
                if(j<n-1){
                    dp[i][j]+=(dp[i][j+1]==-1)?0:dp[i][j+1];
                }
            }
        }
        return (dp[0][0]==-1)?0:dp[0][0];
    }
};