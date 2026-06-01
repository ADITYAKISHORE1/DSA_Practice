class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lb=lower_bound(nums.begin(),nums.end(),target);
        int l=lb-nums.begin();
        if(lb==nums.end() or nums[l]!=target) return {-1,-1};
        int ub=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        return {l,ub-1};
    }
};