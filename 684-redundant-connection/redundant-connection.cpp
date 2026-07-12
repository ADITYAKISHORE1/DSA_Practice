class Solution {
    bool isConnected(int u,int v,vector<vector<int>>&adj,vector<int>&vis){
        if(u==v) return true;
        vis[u]=1;
        bool t=false;
        for(auto& n:adj[u]){
            if(!vis[n]){
                t|=isConnected(n,v,adj,vis);
            }
        }
        return t;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n+1);
        for(auto&e:edges){
            vector<int> vis(n+1,0);
            if(isConnected(e[0],e[1],adj,vis)){
                return {e[0],e[1]};
            }
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return {-1,-1};
    }
};