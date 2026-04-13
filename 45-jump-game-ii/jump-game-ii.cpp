class Solution {
public:
    int jump(vector<int>& nums) {
        int jmp=0,near=0,far=0;
        while(far<nums.size()-1){
            int farthest=0;
            int i=near;
            while(i<=far){
                farthest=max(farthest,i+nums[i]);
                i++;
            }
            near=far+1;
            far=farthest;
            jmp++;
        }
        return jmp;
    }
};