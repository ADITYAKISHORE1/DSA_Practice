class Solution {
    vector<int> sieve(int x){
        vector<int> ans;
        for(int i=2;i*i<=x;i++){
            if(x%i==0){
                ans.push_back(i);
                while(x%i==0){
                    x/=i;
                }
            }
        }
        if(x>1) ans.push_back(x);
        return ans;
    }
    vector<bool> isAval;
    vector<int> vis;
    vector<vector<int>> adj;
    int dfs(int node){
        vis[node]=1;
        int cnt=isAval[node];
        for(auto& adjNode:adj[node]){
            if(vis[adjNode]==0){
                cnt+=dfs(adjNode);
            }
        }
        return cnt;
    }
public:
    int largestComponentSize(vector<int>& nums) {
        isAval.resize(1e5+1,0);
        for(auto& i:nums){
            isAval[i]=1;
        }
        adj.resize(1e5+1);
        vis.resize(1e5+1,0);
        vector<int> fac;
        for(auto&i:nums){
            fac=sieve(i);
            for(auto& j:fac){
                if(i==j) continue;
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
        int maxCnt=0;
        for(int i=2;i<adj.size();i++){
            if(vis[i]==0){
                maxCnt=max(maxCnt,dfs(i));
            }
        }
        return maxCnt;
    }
};