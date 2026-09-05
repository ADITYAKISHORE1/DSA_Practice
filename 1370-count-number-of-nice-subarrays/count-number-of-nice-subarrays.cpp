class Solution {
    int f(vector<int>& v, int k) {
        int oddCnt = 0;
        int l = 0;
        int subarrayCnt = 0;
        for (int r = 0; r < v.size(); r++) {
            if (v[r] % 2 == 1)
                oddCnt++;
            while (l <= r and oddCnt > k) {
                if (v[l] % 2 == 1)
                    oddCnt--;
                l++;
            }
            subarrayCnt += r - l + 1;
        }
        return subarrayCnt;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k - 1);
    }
};