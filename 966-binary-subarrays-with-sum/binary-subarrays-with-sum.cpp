class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int> pref(n,0);
        pref[0]=nums[0];
        for(int i=1;i<n;i++) pref[i]=pref[i-1]+nums[i];
        unordered_map<int,int> freq;
        freq[0]=1;
        int cnt=0;
        for(int i=0;i<n;i++){
            int t=pref[i]-goal;
            cnt+=freq[t];
            freq[pref[i]]++;
        }
        return cnt;
    }
};