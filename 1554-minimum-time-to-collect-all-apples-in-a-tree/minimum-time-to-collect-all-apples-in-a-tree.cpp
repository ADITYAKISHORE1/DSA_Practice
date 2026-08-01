class Solution {
    vector<int> vis;
    int dfs(int node,vector<vector<int>> & adj,vector<bool>& hasApple){
        vis[node]=1;
        int cnt=0;
        for(int adjNode:adj[node]){
            if(vis[adjNode]==0) cnt+=dfs(adjNode,adj,hasApple);
        }
        if(cnt>0) return 2+cnt;
        if(hasApple[node]) return 2;
        return 0;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto& i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vis.resize(n,0);
        int cnt=0;
        vis[0]=1;
        for(auto& i:adj[0]){
            cnt+=dfs(i,adj,hasApple);
        }
        return cnt;
    }
};