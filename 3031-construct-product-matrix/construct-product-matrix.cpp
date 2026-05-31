class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD=12345;
        int n=grid.size();
        int m=grid[0].size();
        vector<int> v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v.push_back(grid[i][j]);
            }
        }
        int nm=v.size();
        vector<int> a(nm,1);
        for(int i=1;i<nm;i++){
            a[i]=((a[i-1]%MOD)*(v[i-1]%MOD))%MOD;
        }
        int suf=1;
        for(int i=nm-2;i>=0;i--){
            suf=((suf%MOD)*(v[i+1]%MOD))%MOD;
            a[i]=((suf%MOD)*(a[i]%MOD))%MOD;
        }
        for(int i=0;i<nm;i++){
            int x=(i/m);
            int y=(i%m);
            grid[x][y]=a[i];
        }
        return grid;
    }
};