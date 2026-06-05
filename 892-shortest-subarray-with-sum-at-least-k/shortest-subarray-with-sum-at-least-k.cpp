class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + nums[i - 1];
        int ans = n + 1;
        deque<int> dq;
        for (int r = 0; r <= n; r++) {
            while (!dq.empty() and pref[r] - pref[dq.front()] >= k) {
                ans = min(ans, (int)r - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() and pref[r] <= pref[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(r);
        }
        return (ans==n+1)?-1:ans;
    }
};