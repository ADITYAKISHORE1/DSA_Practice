class Solution {
    int maxm;
    vector<int> ans, v, vis;
    void dfs(int n, int bit) {
        if (!ans.empty())
            return;
        if (v.size() == n) {
            ans = v;
            return;
        }
        for (int i = 0; i < bit; i++) {
            int val = v.back();
            int t = val ^ (1 << i);
            if (t < n and vis[t] == 0) {
                vis[t] = 1;
                v.push_back(t);
                dfs(n, bit);
                v.pop_back();
                vis[t] = 0;
            }
        }
    }

public:
    vector<int> grayCode(int n) {
        maxm = pow(2, n);
        vis.resize(maxm, 0);
        v.push_back(0);
        vis[0] = 1;
        dfs(maxm, n);
        return ans;
    }
};