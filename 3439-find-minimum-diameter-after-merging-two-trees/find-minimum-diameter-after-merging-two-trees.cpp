class Solution {
    int dfs(int node,int par,vector<vector<int>>& adj,int& diam){
        int max1=0,max2=0;
        for(auto& adjNode:adj[node]){
            if(adjNode!=par){
                int d=dfs(adjNode,node,adj,diam);
                // cout<<d<<endl;
                if(d>max1){
                    max2=max1;
                    max1=d;
                }else if(d>max2){
                    max2=d;
                }
            }
        }
        // cout<<max1<<" "<<max2<<endl;
        diam=max(diam,max1+max2);
        return 1+max1;
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size();
        int m=edges2.size();
        vector<vector<int>> adj1(n+1),adj2(m+1);
        for(auto& i: edges1){
            adj1[i[0]].push_back(i[1]);
            adj1[i[1]].push_back(i[0]);
        }
        for(auto& i: edges2){
            adj2[i[0]].push_back(i[1]);
            adj2[i[1]].push_back(i[0]);
        }
        int diam1=0,diam2=0;
        dfs(0,-1,adj1,diam1);
        dfs(0,-1,adj2,diam2);
        int ans=(diam1+1)/2+(diam2+1)/2+1;
        return max({ans,diam1,diam2});
    }
};