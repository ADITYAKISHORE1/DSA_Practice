class Solution {
    void dfs(int i,vector<vector<int>>&adj,vector<int>& vis){
        vis[i]=1;
        for(int j=0;j<adj[i].size();j++){
            if(adj[i][j]==1 and vis[j]==0){
                dfs(j,adj,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 and vis[i]!=1){
                    cnt++;
                    dfs(i,isConnected,vis);
                }
            }
        }
        return cnt;
    }
};