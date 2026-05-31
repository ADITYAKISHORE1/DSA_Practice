class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=nums[n - 1] - nums[0];
        int maxm, minm;
        for(int i=0;i<n-1;i++){
            maxm=max(nums[i]+k,nums[n-1]-k); // considering +k upto ith idx
            minm=min(nums[i+1]-k,nums[0]+k); // and -k from i+1 to n idx
            ans=min(ans,maxm-minm);         // ith idx will be break even point
        }
        return ans;
    }
};