class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> cur(n,0);
        vector<int> prev(n,0);
        prev[n-1]=grid[m-1][n-1];
        for(int j=n-2;j>=0;j--) prev[j]=grid[m-1][j]+prev[j+1];

        for(int i=m-2;i>=0;i--){
            cur[n-1]=prev[n-1]+grid[i][n-1];
            for(int j=n-2;j>=0;j--){
                cur[j]=grid[i][j]+min(prev[j],cur[j+1]);
            }
            prev=cur;
        }
        return prev[0];
    }
};