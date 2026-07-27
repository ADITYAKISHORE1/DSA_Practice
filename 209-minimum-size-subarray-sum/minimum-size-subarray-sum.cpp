class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        int ans=INT_MAX;
        int curSum=0;
        while(l<n){
            while(r<n and curSum<target){
                curSum+=nums[r];
                r++;
            }
            if(curSum>=target) ans=min(ans,r-l);
            curSum-=nums[l];
            l++;
        }
        return (ans==INT_MAX)?0:ans;
    }
};