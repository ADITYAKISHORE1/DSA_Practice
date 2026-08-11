class DSU{
    vector<int> par;
    vector<int> size;
public:
    DSU(int n){
        size.resize(n,1);
        for(int i=0;i<n;i++) par.push_back(i);
    }

    int find(int n){
        if(par[n]==n) return n;
        return par[n]=find(par[n]);
    }

    void unite(int u,int v){
        int par_u=find(u);
        int par_v=find(v);

        if(par_u==par_v) return;
        if(size[par_u]>size[par_v]){
            size[par_u]+=size[par_v];
            par[par_v]=par_u;
        }else{
            size[par_v]+=size[par_u];
            par[par_u]=par_v;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int> emailMap;
        DSU* d=new DSU(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string email=accounts[i][j];
                if(!emailMap.count(email)){
                    emailMap[email]=i;
                }else{
                    d->unite(i,emailMap[email]);
                }
            }
        }
        vector<string> merged[n];
        for(auto i:emailMap){
            int root=d->find(i.second);
            merged[root].push_back(i.first);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(merged[i].empty()) continue;
            sort(merged[i].begin(), merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            temp.insert(temp.end(),merged[i].begin(),merged[i].end());
            ans.push_back(temp);
        }
        return ans;
    }
};