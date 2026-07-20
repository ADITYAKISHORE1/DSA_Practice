class Solution {
    const int MOD=1e9+7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,long long>>> adj(n);
        for(auto i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> pq;
        vector<long long> dist(n,LLONG_MAX);
        vector<long long> ways(n,0);
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            auto [d,node]=pq.top();
            pq.pop();
            if (d > dist[node]) continue;
            for(auto& [adjNode,wt]:adj[node]){
                if(dist[adjNode]>d+wt){
                    dist[adjNode]=d+wt;
                    pq.push({dist[adjNode],adjNode});
                    ways[adjNode]=ways[node];
                }else if(dist[adjNode]==d+wt){
                    ways[adjNode]=(ways[adjNode]+ways[node])%MOD;
                }
            }
        }
        return ways[n-1];
    }
};