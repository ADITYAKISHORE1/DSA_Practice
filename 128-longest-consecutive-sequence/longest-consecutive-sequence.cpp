class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxCnt = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        for (auto& i : st) {
            int len = 1;
            if (!st.count(i - 1)) {
                while (st.count(i + len))
                    len++;
            }
            maxCnt = max(maxCnt, len);
        }
        return maxCnt;
    }
};