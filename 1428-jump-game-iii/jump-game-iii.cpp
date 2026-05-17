class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        q.push(start);
        vector<int> vis(n, 0);
        vis[start] = 1;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            if (arr[x] == 0)
                return true;
            int l = x - arr[x];
            int r = x + arr[x];
            if (l >= 0 and !vis[l]) {
                vis[l] = 1;
                q.push(l);
            }
            if (r < n and !vis[r]) {
                vis[r] = 1;
                q.push(r);
            }
        }
        return false;
    }
};