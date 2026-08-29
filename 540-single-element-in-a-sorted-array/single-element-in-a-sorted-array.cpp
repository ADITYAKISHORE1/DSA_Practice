class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if((mid>0 and nums[mid]==nums[mid-1]) or (mid<n-1 and nums[mid]==nums[mid+1])){
                if(mid>0 and nums[mid]==nums[mid-1]){
                    int lsize=mid+1;
                    int rsize=n-mid-1;
                    if(lsize%2==0){
                        l=mid+1;
                    }else r=mid-1;
                }else{
                    int lsize=mid;
                    int rsize=n-mid;
                    if(rsize%2==0){
                        r=mid-1;
                    }else l=mid+1;
                }
            }else return nums[mid];
        }
        return -1;
    }
};