class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int curSum=0,gloSum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(curSum<0) curSum=0;
            curSum+=nums[i];
            gloSum=max(gloSum,curSum);
        }
        return max(gloSum,curSum);
    }
};
