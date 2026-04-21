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
    int find(int n) {
        if (par[n] == n)
            return n;
        return par[n] = find(par[n]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            par[b] = a;
            size[a] += size[b];
        }
    }
};
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU* d= new DSU(1e5+5);
        for (auto& i : allowedSwaps) {
            d->unite(i[0],i[1]);
        }
        int cnt=0;
        unordered_map<int,unordered_map<int,int>> grp;
        for(int i=0;i<n;i++){
            int p=d->find(i);
            grp[p][source[i]]++;
        }
        for(int i=0;i<n;i++){
            int p=d->find(i);
            if(grp[p][target[i]]>0){
                grp[p][target[i]]--;
            }else cnt++;
        }
        return cnt;
    }
};