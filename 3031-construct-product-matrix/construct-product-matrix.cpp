class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> a(n, vector<int>(m));
        int pref = 1;
        for (int i = 0; i < n * m; i++) { // pref calc
            a[i / m][i % m] = pref;
            pref = ((grid[i / m][i % m] % MOD) * pref) % MOD;
        }
        int suf = 1;
        for (int i = n * m - 1; i >= 0; i--) { // suf calc and final ans prep
            a[i / m][i % m] = (a[i / m][i % m] * suf) % MOD;  // pref * suf
            suf = (suf * (grid[i / m][i % m] % MOD)) % MOD;
        }
        return a;
    }
};