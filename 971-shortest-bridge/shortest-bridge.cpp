class Solution {
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
    void dfs(int x,int y,int & n,vector<vector<int>>& grid,vector<vector<int>>&vis){
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 and ny>=0 and nx<n and ny<n and grid[nx][ny]==1 and vis[nx][ny]==0 ){
                dfs(nx,ny,n,grid,vis);
            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            bool ck=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(i,j,n,grid,vis);
                    ck=1;
                    break;
                }
            }
            if(ck) break;
        }
        vector<pair<int,int>> island1,island2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(vis[i][j]==1){
                        island1.push_back({i,j});
                    }else{
                        island2.push_back({i,j});
                    }
                }
            }
        }
        int ans=INT_MAX;
        for(auto& [x1,y1]:island1){
            for(auto& [x2,y2]:island2){
                int d=abs(x2-x1)+abs(y2-y1)-1;
                ans=min(ans,d);
            }
        }
        return ans;
    }
};