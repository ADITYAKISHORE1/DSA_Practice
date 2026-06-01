class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1,mid;
        int ans=1e9;
        while(l<=r){
            mid=l+(r-l)/2;
            if(nums[mid]<=nums[r]){
                ans=min(ans,nums[mid]);
                r=mid-1;
            }else {
                l=mid+1;
            }
        }
        return ans;
    }
};