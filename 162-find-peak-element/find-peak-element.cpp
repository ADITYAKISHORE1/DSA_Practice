class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        int peak=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(mid>0 and mid<n-1 and nums[mid]>=nums[mid-1] and nums[mid]>=nums[mid+1]){
                return mid;
            }else if(mid>0){
                if(nums[mid]>=nums[mid-1]) {
                    peak=mid;
                    l=mid+1;}
                else r=mid-1;
            }else if(mid<n-1){
                if(nums[mid]>=nums[mid+1]){
                    peak=mid;
                    r=mid-1;
                }else l=mid+1;
            }else{
                l++;
                r--;
            }
        }
        return peak;
    }
};