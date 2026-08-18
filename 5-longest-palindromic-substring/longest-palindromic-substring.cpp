class Solution {
public:
    string longestPalindrome(string s) {
        string t = "#";
        for (auto& c : s)
            t += c + string("#");
        int n = t.size();
        vector<int> p(n, 0);
        int l = 0, r = -1;
        int idx = -1, maxm = 0;
        for (int i = 0; i < n; i++) {
            if (r >= i)
                p[i] = min(r - i, p[l + r - i]);
            while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n &&
                   t[i - p[i] - 1] == t[i + p[i] + 1]) {
                p[i]++;
            }
            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
            if (maxm < p[i]) {
                idx = i;
                maxm = p[i];
            }
        }
        string ans;
        for (int i = idx - maxm; i <= idx + maxm; i++) {
            if (t[i] != '#')
                ans += t[i];
        }
        return ans;
    }
};