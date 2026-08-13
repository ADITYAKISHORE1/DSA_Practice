class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int a = 0, b = 0, c = 0;
        for (int i = n - 1; i >= 0; i--) {
            int t = INT_MIN;
            int s = stoneValue[i];
            t = max(t, s - a);
            if (i < n - 1) {
                s += stoneValue[i + 1];
                t = max(t, s - b);
            }
            if (i < n - 2) {
                s += stoneValue[i + 2];
                t = max(t, s - c);
            }
            c = b;
            b = a;
            a = t;
        }
        if (a > 0)
            return "Alice";
        else if (a < 0)
            return "Bob";
        return "Tie";
    }
};