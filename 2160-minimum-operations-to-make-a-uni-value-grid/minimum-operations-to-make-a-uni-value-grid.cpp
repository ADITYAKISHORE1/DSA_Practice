class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        for (auto& i : grid)
            for (auto& j : i)
                v.push_back(j);
        sort(v.begin(), v.end());
        int r = v[(v.size() / 2)];
        int ay = 0;
        for (auto& i : v) {
            int a = abs(i - r);
            if (a % x != 0) {
                ay = 1e9;
                break;
            }
            ay += a / x;
        }
        if (ay == 1e9)
            return -1;
        return (ay==1e9?-1:ay);
    }
};