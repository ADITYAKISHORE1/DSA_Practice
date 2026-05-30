class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;
        pq.push({grid[0][0],0,0});
        vis[0][0]=1;
        vector<int> dx={0,0,1,-1};
        vector<int> dy={1,-1,0,0};
        while(!pq.empty()){
            auto [v,x,y]=pq.top();
            pq.pop();
            if(x==n-1 and y==n-1) return v;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 and ny>=0 and nx<n and ny<n and !vis[nx][ny]){
                    pq.push({max(v,grid[nx][ny]),nx,ny});
                    vis[nx][ny]=1;
                }
            }
        }
        return -1;
    }
};