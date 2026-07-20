class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int> dist(n,1e9);
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;
        pq.push({0,0,src});
        dist[src]=0;
        while(!pq.empty()){
            auto [K,dis,node]=pq.top();
            pq.pop();
            for(auto& [adjNode,wt]:adj[node]){
                if(dist[adjNode]>dis+wt and K<=k){
                    dist[adjNode]=dis+wt;
                    pq.push({K+1,dis+wt,adjNode});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};