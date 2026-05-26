class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> pref(n,1),suf(n,1);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]*nums[i];
        }
        suf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=suf[i+1]*nums[i];
        }
        vector<int> ans(n,1);
        for(int i=0;i<n;i++){
            if(i>0) ans[i]*=pref[i-1];
            if(i<n-1) ans[i]*=suf[i+1];
        }
        return ans;
    }
};