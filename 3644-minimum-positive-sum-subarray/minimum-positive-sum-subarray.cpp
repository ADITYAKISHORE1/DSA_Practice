class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int ans=INT_MAX;
        vector<int> pref=nums;
        for(int i=1;i<n;i++) pref[i]+=pref[i-1];
        for(int i=0;i<n;i++){
            for(int j=i+l-1;j<min(n,i+r);j++){
                int diff=pref[j]-((i>0)?pref[i-1]:0);
                if(diff>0) ans=min(ans,diff);
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }
};