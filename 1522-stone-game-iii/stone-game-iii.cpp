class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int t = INT_MIN;
            int s = stoneValue[i];
            t = max(t, s - dp[i + 1]);
            if (i < n - 1) {
                s += stoneValue[i + 1];
                t = max(t, s - dp[i + 2]);
            }
            if (i < n - 2) {
                s += stoneValue[i + 2];
                t = max(t, s - dp[i + 3]);
            }
            dp[i] = t;
        }
        if (dp[0] > 0)
            return "Alice";
        else if (dp[0] < 0)
            return "Bob";
        return "Tie";
    }
};