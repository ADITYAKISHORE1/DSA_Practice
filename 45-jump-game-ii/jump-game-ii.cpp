class Solution {
public:
    int jump(vector<int>& nums) {
        int jmp=0,near=0,far=0;
        while(far<nums.size()-1){
            int farthest=0;
            while(near<=far){
                farthest=max(farthest,near+nums[near]);
                near++;
            }
            far=farthest;
            jmp++;
        }
        return jmp;
    }
};