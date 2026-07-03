class Solution {
    int maxm;
    vector<int> ans, v, vis;
    void dfs(int bit) {
        if (!ans.empty())
            return;
        if (v.size() == maxm) {
            ans = v;
            return;
        }
        for (int i = 0; i < bit; i++) {
            int t = v.back() ^ (1 << i);
            if (t < maxm and vis[t] == 0) {
                vis[t] = 1;
                v.push_back(t);
                dfs(bit);
                v.pop_back();
                vis[t] = 0;
            }
        }
    }

public:
    vector<int> grayCode(int n) {
        maxm = (1 << n);
        vis.resize(maxm, 0);
        v.push_back(0);
        vis[0] = 1;
        dfs(n);
        return ans;
    }
};