class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxm=*max_element(nums.begin(),nums.end());
        long long minm=*min_element(nums.begin(),nums.end());
        return (maxm-minm)*k;
    }
};