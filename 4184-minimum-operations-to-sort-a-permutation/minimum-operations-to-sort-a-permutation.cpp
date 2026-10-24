class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int st = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                st = i;
                break;
            }
        }

        bool forward = true, backward = true;

        for (int i = 0; i < n; i++) {
            if (nums[(st + i) % n] != i)
                forward = false;

            if (nums[(st - i + n) % n] != i)
                backward = false;
        }

        int ans = INT_MAX;

        if (forward) {
            // Direct left rotations
            ans = min(ans, st);

            // Reverse -> left rotations -> reverse
            ans = min(st, 2 + (n - st) % n);
        }

        if (backward) {
            // Reverse first, then rotate left
            ans = min(ans, 1 + (n - 1 - st));

            // Rotate left first, then reverse
            ans = min(ans, 1 + (st + 1) % n);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};