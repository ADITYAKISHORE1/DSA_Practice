class DSU {
    vector<int> par;
    vector<int> size;

public:
    DSU(int n) {
        par.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            par[i] = i;
    }

    int find(int v) {
        if (par[v] == v)
            return v;
        return par[v] = find(par[v]);
    }

    void unite(int u, int v) {
        int par_u = find(u);
        int par_v = find(v);

        if (par_u == par_v)
            return;
        else if (size[par_u] < size[par_v]) {
            size[par_v] += size[par_u];
            par[par_u] = par_v;
        } else {
            size[par_u] += size[par_v];
            par[par_v] = par_u;
        }
    }
};
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end()) + 1;
        DSU* d = new DSU(m);
        for (auto& i : nums) {
            int n = i;
            for (int j = 2; j * j <= n; j++) {
                if (n % j == 0) {
                    d->unite(i, j);
                    while (n % j == 0)
                        n /= j;
                }
            }
            if (n > 1)
                d->unite(i, n);
        }
        int maxCnt = 0;
        unordered_map<int, int> mpp;
        for (auto& i : nums) {
            maxCnt = max(maxCnt, ++mpp[d->find(i)]);
        }
        return maxCnt;
    }
};