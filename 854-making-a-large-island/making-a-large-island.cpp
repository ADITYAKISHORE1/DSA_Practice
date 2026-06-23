class DSU {
    vector<int> par;
    vector<int> size;

public:
    DSU(int n) {
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            par.push_back(i);
    }

    int find(int v) {
        if (v == par[v])
            return v;
        return par[v] = find(par[v]);
    }

    void unite(int u, int v) {
        int par_u = find(u);
        int par_v = find(v);

        if (par_u == par_v)
            return;
        else if (size[par_u] > size[par_v]) {
            size[par_u] += size[par_v];
            par[par_v] = par_u;
        } else {
            size[par_v] += size[par_u];
            par[par_u] = par_v;
        }
    }
    int getSize(int n) { return size[find(n)]; }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU* d = new DSU(n * n);
        int maxSize = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int v = n * i + j;
                    if (i > 0 and grid[i - 1][j] == 1)
                        d->unite(v, v - n);
                    if (j > 0 and grid[i][j - 1] == 1)
                        d->unite(v, v - 1);
                    if (i < n - 1 and grid[i + 1][j] == 1)
                        d->unite(v, v + n);
                    if (j < n - 1 and grid[i][j + 1] == 1)
                        d->unite(v, v + 1);
                    maxSize = max(maxSize, d->getSize(v));
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int v = n * i + j;
                    unordered_set<int> st;
                    int sz = 1;
                    int par;
                    if (i > 0 and grid[i - 1][j] == 1) {
                        par = d->find(v - n);
                        if (!st.count(par)) {
                            st.insert(par);
                            sz += d->getSize(v - n);
                        }
                    }
                    if (j > 0 and grid[i][j - 1] == 1) {
                        par = d->find(v - 1);
                        if (!st.count(par)) {
                            st.insert(par);
                            sz += d->getSize(v - 1);
                        }
                    }
                    if (i < n - 1 and grid[i + 1][j] == 1) {
                        par = d->find(v + n);
                        if (!st.count(par)) {
                            st.insert(par);
                            sz += d->getSize(v + n);
                        }
                    }
                    if (j < n - 1 and grid[i][j + 1] == 1) {
                        par = d->find(v + 1);
                        if (!st.count(par)) {
                            st.insert(par);
                            sz += d->getSize(v + 1);
                        }
                    }
                    maxSize = max(maxSize, sz);
                }
            }
        }

        return maxSize;
    }
};