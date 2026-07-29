class Solution {
    bool pred(vector<int>&v,int lim,int k){
        int cnt=0;
        for(int i=0;i<v.size();i++){
            if(v[i]<=lim){
                cnt++;
                i++;
            }
        }
        return cnt>=k;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        int l=1,r=1e9;
        while(l<r){
            int mid=l+(r-l)/2;
            if(pred(nums,mid,k)){
                r=mid;
            }else l=mid+1;
        }
        return l;
    }
};