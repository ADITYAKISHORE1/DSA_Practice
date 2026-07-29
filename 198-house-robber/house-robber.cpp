class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> cur(2, 0);
        vector<int> prev(2, 0);
        prev[1] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            cur[1] = nums[i] + prev[0];
            cur[0] = max(prev[0], prev[1]);
            prev = cur;
        }

        return max(prev[true], prev[false]);
    }
};