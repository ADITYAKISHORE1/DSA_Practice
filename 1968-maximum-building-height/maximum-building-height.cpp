class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        int m = restrictions.size();
        sort(restrictions.begin(), restrictions.end());
        for (int i = 1; i < m; i++) {
            restrictions[i][1] =
                min(restrictions[i][1], restrictions[i - 1][1] +
                                            restrictions[i][0] -
                                            restrictions[i - 1][0]);
        }
        for (int i = m - 2; i >= 0; i--) {
            restrictions[i][1] =
                min(restrictions[i][1], restrictions[i + 1][1] +
                                            restrictions[i + 1][0] -
                                            restrictions[i][0]);
        }
        int maxm = restrictions[m - 1][1] + n - restrictions[m - 1][0];
        for (int i = 1; i < m; i++) {
            int x1 = restrictions[i - 1][0];
            int x2 = restrictions[i][0];
            int h1 = restrictions[i - 1][1];
            int h2 = restrictions[i][1];
            maxm = max(maxm, (h1 + h2 + x2 - x1) / 2);
        }
        return maxm;
    }
};