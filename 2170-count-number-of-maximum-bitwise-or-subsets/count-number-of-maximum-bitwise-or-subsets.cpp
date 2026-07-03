class Solution {
    int cnt = 0;
    int maxOR = -1;
    void f(int i, int curOR, vector<int>& v) {
        if (i == v.size()) {
            if (curOR > maxOR) {
                maxOR = curOR;
                cnt = 1;
            } else if (curOR == maxOR)
                cnt++;
            return;
        }
        f(i + 1, (curOR | v[i]), v);
        f(i + 1, curOR, v);
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        f(0, 0, nums);
        return cnt;
    }
};