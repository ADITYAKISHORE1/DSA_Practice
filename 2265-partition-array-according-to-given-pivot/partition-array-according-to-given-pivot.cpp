class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);
        int l = 0, r = n - 1;
        int i = 0, j = n - 1;
        while (i < n) {
            if (pivot > nums[i])
                ans[l++] = nums[i];
            if (nums[j] > pivot)
                ans[r--] = nums[j];
            i++;
            j--;
        }
        while (l <= r)
            ans[l++] = pivot;
        return ans;
    }
};