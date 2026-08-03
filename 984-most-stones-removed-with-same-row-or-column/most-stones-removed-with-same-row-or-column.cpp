class DSU {
    vector<int> par;
    vector<int> size;

public:
    DSU(int n) {
        size.resize(n,1);
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }
    int find(int n) {
        if (par[n] == n)
            return n;
        return par[n] = find(par[n]);
    }
    void unite(int u, int v) {
        int par_u = find(u);
        int par_v = find(v);

        if (par_u == par_v)
            return;
        if (size[par_u] > size[par_v]) {
            size[par_u] += size[par_v];
            par[par_v] = par_u;
        } else {
            size[par_v] += size[par_u];
            par[par_u] = par_v;
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DSU d(30001);
        set<int> st;
        int offset=10001; 
        for(auto& i:stones){
            d.unite(i[0],i[1]+offset);
            st.insert(i[0]);
            st.insert(i[1]+offset);
        }
        int cnt=0;
        for(auto i:st){
            if(d.find(i)==i) cnt++;
        }
        return stones.size()-cnt;
    }
};