class DSU {
    vector<int> par;
    vector<int> size;

public:
    DSU(int n) {
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            par.push_back(i);
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
        if (size[par_v] > size[par_u]) {
            par[par_u] = par_v;
            size[par_v] += size[par_u];
        } else {
            par[par_v] = par_u;
            size[par_u] += size[par_v];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU* d = new DSU(n);
        int extraEdge = 0;
        for (auto i : connections) {
            if (d->find(i[0]) == d->find(i[1])) {
                extraEdge++;
            } else
                d->unite(i[0], i[1]);
        }
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            int par = d->find(i);
            st.insert(par);
        }
        if (st.size()-1 > extraEdge)
            return -1;
        return st.size()-1;
    }
};