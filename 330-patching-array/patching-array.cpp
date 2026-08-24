class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patches=0;
        long long maxReach=0;
        for(int i=0;i<nums.size() and maxReach<n;){
            if(maxReach+1>=nums[i]){
                maxReach+=nums[i];
                i++;
            }else{
                maxReach+=maxReach+1;
                patches++;
            }
        }
        // // cout<<maxReach;
        while(maxReach<n){
            patches++;
            maxReach+=maxReach+1;
        }
        return patches;
    }
};