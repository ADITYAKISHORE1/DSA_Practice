class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int b1 = 0;
        for (auto& i : nums1)
            b1 ^= i;
        int b2 = 0;
        for (auto& i : nums2)
            b2 ^= i;
        if (n % 2 == 0 and m % 2 == 0)
            return 0;
        if (n % 2) {
            if (m % 2)
                return b1 ^ b2;
            return b2;
        }
        return b1;
    }
};