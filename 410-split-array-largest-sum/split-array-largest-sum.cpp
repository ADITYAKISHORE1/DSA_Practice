class Solution {
    bool pred(int maxsum, vector<int>& v, int k) {
        int cursum = 0;
        for (auto& i : v) {
            if (cursum+i > maxsum) {
                k--;
                cursum=i;
            }else cursum+=i;
        }
        return k>=0;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int l = *max_element(nums.begin(),nums.end()), r = accumulate(nums.begin(),nums.end(),0);
        while (l < r) {
            int mid = l + (r - l) / 2;
            if ( pred(mid, nums, k-1)) {
                r = mid;
            } else
                l = mid + 1;
        }
        return l;
    }
};