class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) return 1;
        long long K=k;
        sort(nums.begin(),nums.end());
        int l=0,r=0;
        int win=0;
        while(r<n-1){
            if((long long)(nums[r+1]-nums[r])*(r-l+1)<=K){
                K-=(nums[r+1]-nums[r])*(r-l+1);
                r++;
            }else{
                K+=nums[r]-nums[l];
                l++;
            }
            win=max(win,r-l+1);
        }
        return win;
    }
};