class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        int prefMax=INT_MIN;
        int i=0;
        while(i<n){
            int mn=nums[i],mx=nums[i];
            int bit=__builtin_popcount(nums[i]);
            while(i<n and bit==__builtin_popcount(nums[i])){
                mx=max(mx,nums[i]);
                mn=min(mn,nums[i]);
                i++;
            }
            if(prefMax>mn) return false;
            prefMax=mx;
        }
        return true;
    }
};