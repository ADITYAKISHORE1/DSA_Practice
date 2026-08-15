class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>> adj(m,vector<int>(n,1e9));
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]){
                    adj[i][j]=0;
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        vector<int> dx={0,0,-1,1};
        vector<int> dy={-1,1,0,0};
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto [x,y]=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(nx>=0 and nx<m and ny>=0 and ny<n and vis[nx][ny]==0){
                        if(isWater[nx][ny]==0){
                            adj[nx][ny]=min(adj[nx][ny],adj[x][y]+1);
                            vis[nx][ny]=1;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
        return adj;
    }
};