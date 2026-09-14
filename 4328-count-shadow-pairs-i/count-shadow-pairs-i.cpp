class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int r = 0;
        long long cnt = 0;
        stack<pair<int, int>> st;
        while (r < nums.size()) {
            while (!st.empty() and st.top().first > nums[r]) {
                st.pop();
            }
            int eqCnt = 0;
            if (!st.empty() and st.top().first == nums[r]) {
                eqCnt = st.top().second;
                st.pop();
            }
            if (!st.empty())
                cnt += st.top().second;
            if (eqCnt > 0)
                st.push({nums[r], eqCnt + 1});
            else
                st.push({nums[r], ((!st.empty()) ? st.top().second : 0) + 1});
            r++;
        }
        return cnt;
    }
};