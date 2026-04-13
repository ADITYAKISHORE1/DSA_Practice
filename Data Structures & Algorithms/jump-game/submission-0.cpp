class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int target=n-1;
        bool ans=1;
        for(int i=n-2;i>=0;i--){
            if(i+nums[i]>=target){ 
                target=i;
                ans=1;
            }else ans=0;
        }
        return ans;
    }
};
